#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int cnt;
};

int k, w, h;
vector<vector<int>> map;
vector<vector<vector<int>>> visited;

int h_dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int h_dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x, 0});

  visited[y][x][0] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (map[ny][nx] == 1) continue;

      if (visited[ny][nx][now.cnt] == -1) {
        visited[ny][nx][now.cnt] = visited[now.row][now.col][now.cnt] + 1;
        que.push({ny, nx, now.cnt});
      }
    }

    if (now.cnt < k) {
      for (int i = 0; i < 8; i++) {
        int ny = now.row + h_dy[i];
        int nx = now.col + h_dx[i];

        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (map[ny][nx] == 1) continue;

        if (visited[ny][nx][now.cnt + 1] == -1) {
          visited[ny][nx][now.cnt + 1] = visited[now.row][now.col][now.cnt] + 1;
          que.push({ny, nx, now.cnt + 1});
        }
      }
    }
  }
}

int main() {
  cin >> k >> w >> h;

  map.resize(h, vector<int>(w, 0));
  visited.resize(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map[i][j];
    }
  }

  bfs(0, 0);

  int res = -1;

  for (int i = 0; i <= k; i++) {
    int val = visited[h - 1][w - 1][i];

    if (val == -1) continue;
    if (res == -1 || res > val) res = val;
  }

  cout << res;

  return 0;
}