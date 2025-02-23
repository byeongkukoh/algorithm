#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct Node {
  int y, x;
};

int n, m;

void bfs(Node start) {
  queue<Node> que;
  que.push(start);

  visited[start.y][start.x] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (visited[ny][nx] != -1) continue;
      if (map[ny][nx] == 0) {
        visited[ny][nx] = 0;
        continue;
      }

      que.push({ny, nx});
      visited[ny][nx] = visited[now.y][now.x] + 1;
    }
  }
}

int main() {
  cin >> n >> m;

  Node start;

  map.resize(n, vector<int>(m, 0));
  visited.resize(n, vector<int>(m, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];

      if (map[i][j] == 2) {
        start.y = i;
        start.x = j;
      }
    }
  }

  bfs(start);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        cout << 0 << " ";
      } else {
        cout << visited[i][j] << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}