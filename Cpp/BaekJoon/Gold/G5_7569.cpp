#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int z, y, x;
};

int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};

int main() {
  int m, n, h;
  cin >> m >> n >> h;

  vector<vector<vector<int>>> tomato;
  tomato.resize(h, vector<vector<int>>(n, vector<int>(m, 0)));

  vector<vector<vector<int>>> visited;
  visited.resize(h, vector<vector<int>>(n, vector<int>(m, 0)));

  queue<Node> que;

  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        cin >> tomato[z][y][x];

        if (tomato[z][y][x] == 1) {
          que.push({z, y, x});
          visited[z][y][x] = 1;
        }

        if (tomato[z][y][x] == -1) {
          visited[z][y][x] = -1;
        }
      }
    }
  }

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 6; i++) {
      int nz = now.z + dz[i];
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;
      if (tomato[nz][ny][nx] == -1) continue;
      if (visited[nz][ny][nx] != 0) continue;

      que.push({nz, ny, nx});
      visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
    }
  }

  int res = 1;
  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (visited[z][y][x] > res) {
          res = visited[z][y][x];
        }

        if (visited[z][y][x] == 0) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  cout << res - 1;

  // for (int z = 0; z < h; z++) {
  //   for (int y = 0; y < n; y++) {
  //     for (int x = 0; x < m; x++) {
  //       cout << tomato[z][y][x] << " ";
  //     }
  //     cout << "\n";
  //   }
  //   cout << "\n";
  // }

  return 0;
}