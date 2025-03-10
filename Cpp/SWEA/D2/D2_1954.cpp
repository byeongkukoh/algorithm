#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  int dy[] = {0, 1, 0, -1};
  int dx[] = {1, 0, -1, 0};

  for (int t = 1; t <= test; t++) {
    int n;
    cin >> n;

    vector<vector<int>> map;
    map.resize(n, vector<int>(n, 0));

    int cnt = 1;
    int idx = 0;

    int row = 0, col = 0;
    map[row][col] = cnt;
    while (cnt < n * n) {
      int ny = row + dy[idx];
      int nx = col + dx[idx];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
        idx = (idx + 1) % 4;
        continue;
      }
      if (map[ny][nx] != 0) {
        idx = (idx + 1) % 4;
        continue;
      }

      row = ny;
      col = nx;

      cnt++;
      map[row][col] = cnt;
    }

    cout << "#" << t << "\n";

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << map[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}