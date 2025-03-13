#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row, col, block;
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> map;
  vector<vector<vector<int>>> visited;

  map.resize(n, vector<int>(m, 0));
  visited.resize(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

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

  Node start = {0, 0, 0};
  queue<Node> que;
  que.push(start);

  visited[0][0][0] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (map[ny][nx] == 1 && now.block == k) continue;

      // 벽이 아니고, 방문하지 않은 경우
      if (map[ny][nx] == 0 && visited[ny][nx][now.block] == 0) {
        visited[ny][nx][now.block] = visited[now.row][now.col][now.block] + 1;
        que.push({ny, nx, now.block});
      }

      // 벽이지만, 부술 횟수가 남아있는 경우
      if (map[ny][nx] == 1 && now.block < k &&
          visited[ny][nx][now.block + 1] == 0) {
        visited[ny][nx][now.block + 1] =
            visited[now.row][now.col][now.block] + 1;
        que.push({ny, nx, now.block + 1});
      }
    }
  }

  int res = INT_MAX;

  for (int i = 0; i < k + 1; i++) {
    if (visited[n - 1][m - 1][i] != 0 && res > visited[n - 1][m - 1][i]) {
      res = visited[n - 1][m - 1][i];
    }
  }

  if (res == INT_MAX) {
    cout << -1;
  } else {
    cout << res;
  }

  return 0;
}