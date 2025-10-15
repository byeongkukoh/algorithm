#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int bfs(int n, int m, vector<vector<int>> map) {
  vector<vector<bool>> visited;
  visited.resize(n + 1, vector<bool>(m + 1, false));

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  int result = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (map[i][j] == 1 && !visited[i][j]) {
        queue<Node> que;

        que.push({i, j});
        visited[i][j] = true;

        int cnt = 1;

        while (!que.empty()) {
          Node now = que.front();
          que.pop();

          for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if (map[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            que.push({ny, nx});
            visited[ny][nx] = true;

            cnt++;
          }
        }

        if (result < cnt) result = cnt;
      }
    }
  }

  return result;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> map;
  map.resize(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < k; i++) {
    int row, col;
    cin >> row >> col;

    map[row][col] = 1;
  }

  int result = bfs(n, m, map);

  cout << result;

  return 0;
}