#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int time;
};

struct Status {
  int stat;
  int time;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Status>> map;
  queue<Node> que;

  map.resize(n, vector<Status>(m, {0, 0}));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j].stat;

      if (map[i][j].stat == 1 || map[i][j].stat == 2) {
        que.push({i, j, 0});
      }
    }
  }

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    if (map[now.y][now.x].stat == 3) continue;

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];
      int nt = now.time + 1;

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (map[ny][nx].stat == -1 || map[ny][nx].stat == 3) continue;

      if (map[ny][nx].stat == 0) {
        que.push({ny, nx, nt});
        map[ny][nx].stat = map[now.y][now.x].stat;
        map[ny][nx].time = nt;
      } else if (map[ny][nx].stat == 1 && map[now.y][now.x].stat == 2 &&
                 map[ny][nx].time == nt) {
        map[ny][nx].stat += map[now.y][now.x].stat;
        map[ny][nx].time = nt;
      } else if (map[ny][nx].stat == 2 && map[now.y][now.x].stat == 1 &&
                 map[ny][nx].time == nt) {
        map[ny][nx].stat += map[now.y][now.x].stat;
        map[ny][nx].time = nt;
      }
    }
  }

  int cnt[4] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j].stat == -1) continue;

      cnt[map[i][j].stat]++;
    }
  }

  for (int i = 1; i < 4; i++) {
    cout << cnt[i] << " ";
  }

  return 0;
}