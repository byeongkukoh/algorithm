#include <iostream>
#include <vector>

using namespace std;

int cntMinus = 0, cntZero = 0, cntPlus = 0;

bool isSame(int r, int c, int size, const vector<vector<int>>& paper) {
  int first = paper[r][c];

  for (int i = r; i < r + size; i++) {
    for (int j = c; j < c + size; j++) {
      if (paper[i][j] != first) return false;
    }
  }

  return true;
}

void solve(int r, int c, int size, const vector<vector<int>>& paper) {
  if (isSame(r, c, size, paper)) {
    int val = paper[r][c];

    if (val == 1)
      cntPlus++;
    else if (val == 0)
      cntZero++;
    else
      cntMinus++;

    return;
  }

  int newSize = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(r + i * newSize, c + j * newSize, newSize, paper);
    }
  }
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> paper(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  solve(0, 0, N, paper);

  cout << cntMinus << "\n";
  cout << cntZero << "\n";
  cout << cntPlus << "\n";

  return 0;
}