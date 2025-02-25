#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

int n, m, k;
// vector<vector<int>> ground;
// vector<vector<int>> visited;
int ground[50][50];
int visited[50][50];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// BFS 탐색
void bfs(Node start) {
  queue<Node> que;
  que.push(start);

  visited[start.y][start.x] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (ground[ny][nx] == 0) continue;
      if (visited[ny][nx] == 1) continue;

      visited[ny][nx] = 1;
      que.push({ny, nx});
    }
  }
}

// 초기화 함수
void init(int n, int m) {
  memset(ground, 0, sizeof(ground));
  memset(visited, 0, sizeof(visited));
}

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    cin >> m >> n >> k;

    init(n, m);
    // ground.resize(n, vector<int>(m, 0));
    // visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;

      ground[y][x] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ground[i][j] == 1 && visited[i][j] != 1) {
          cnt++;
          bfs({i, j});
        }
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}