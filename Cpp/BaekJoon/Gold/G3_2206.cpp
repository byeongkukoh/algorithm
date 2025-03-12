#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int block;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> map;
  map.resize(n, vector<int>(m, 0));

  vector<vector<vector<int>>> visited;
  visited.resize(n, vector<vector<int>>(m, vector<int>(2, 0)));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      if (temp[j] == '0')
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  queue<Node> que;
  que.push({0, 0, 0});

  visited[0][0][0] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      // 벽이 아닌 경우, 그냥 이동
      if (map[ny][nx] == 0 && visited[ny][nx][now.block] == 0) {
        visited[ny][nx][now.block] = visited[now.y][now.x][now.block] + 1;
        que.push({ny, nx, now.block});
      }

      // 벽이지만, 벽을 부술 수 있는 경우
      if (map[ny][nx] == 1 && now.block == 0 && visited[ny][nx][1] == 0) {
        visited[ny][nx][1] = visited[now.y][now.x][0] + 1;
        que.push({ny, nx, 1});
      }
    }
  }

  int res1 = visited[n - 1][m - 1][0];
  int res2 = visited[n - 1][m - 1][1];

  if (res1 == 0 && res2 == 0) {
    cout << -1;
  } else if (res1 == 0) {
    cout << res2;
  } else if (res2 == 0) {
    cout << res1;
  } else {
    cout << min(res1, res2);
  }

  return 0;
}