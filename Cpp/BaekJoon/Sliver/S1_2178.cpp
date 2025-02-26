#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

int n, m;
vector<string> map;
vector<vector<int>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x});
  visited[y][x] = int(map[y][x]) - 48;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

      if (map[ny][nx] == '0') continue;

      if (visited[ny][nx] > visited[now.y][now.x] + int(map[ny][nx]) - 48) {
        visited[ny][nx] = visited[now.y][now.x] + int(map[ny][nx]) - 48;
      } else if (visited[ny][nx] != 0)
        continue;
      else {
        visited[ny][nx] = visited[now.y][now.x] + int(map[ny][nx]) - 48;
      }

      que.push({ny, nx});
    }
  }
}

int main() {
  cin >> n >> m;

  map.resize(n);
  visited.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    cin >> map[i];
  }

  bfs(0, 0);

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << visited[n - 1][m - 1];

  return 0;
}