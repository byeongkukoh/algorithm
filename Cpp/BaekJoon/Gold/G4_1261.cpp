#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int n, m;
vector<vector<int>> map;
vector<vector<int>> dist;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x});

  dist[y][x] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

      int nextdist;
      if (map[ny][nx] == 1) {
        nextdist = dist[now.y][now.x] + 1;
      } else {
        nextdist = dist[now.y][now.x];
      }

      if (dist[ny][nx] != 0 && dist[ny][nx] <= nextdist) continue;

      dist[ny][nx] = nextdist;
      que.push({ny, nx});
    }
  }
}

int main() {
  cin >> m >> n;  // m: 가로 / n: 세로

  map.resize(n, vector<int>(m, 0));
  dist.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      if (temp[j] == '0') {
        map[i][j] = 0;  // 통로
      } else {
        map[i][j] = 1;  // 벽
      }
    }
  }

  // flood fill 수행
  bfs(0, 0);  // 시작위치 (0, 0) / 도착위치 (n-1, m)

  cout << dist[n - 1][m - 1] - 1;

  return 0;
}