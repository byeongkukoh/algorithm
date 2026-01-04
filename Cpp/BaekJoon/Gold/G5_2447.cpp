#include <iostream>
#include <vector>

using namespace std;

void solve(int r, int c, int size, vector<vector<char>>& stars) {
  if (size == 1) {
    stars[r][c] = '*';
    return;
  }

  int newSize = size / 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;

      solve(r + i * newSize, c + j * newSize, newSize, stars);
    }
  }
}

int main() {
  int N;
  cin >> N;

  vector<vector<char>> stars(N, vector<char>(N, ' '));

  solve(0, 0, N, stars);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << stars[i][j];
    }
    cout << "\n";
  }

  return 0;
}