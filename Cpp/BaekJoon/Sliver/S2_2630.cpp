#include <iostream>
#include <vector>

using namespace std;

int n;
int white = 0, blue = 0;
vector<vector<int>> paper;

bool isSame(int x, int y, int size) {
  int color = paper[y][x];

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (color != paper[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void divide(int x, int y, int size) {
  // 기저조건
  if (isSame(x, y, size)) {
    if (paper[y][x] == 0) {
      white++;
    } else {
      blue++;
    }

    return;
  }

  int half = size / 2;

  divide(x, y, half);
  divide(x + half, y, half);
  divide(x, y + half, half);
  divide(x + half, y + half, half);
}

int main() {
  cin >> n;

  paper.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }

  divide(0, 0, n);

  cout << white << "\n";
  cout << blue << "\n";

  return 0;
}