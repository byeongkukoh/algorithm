#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y, x;
  int block;
};

int n;

// 방향배열 - 상하좌우
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<int>> map;
vector<vector<int>> visited;

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x, 0});

  visited[y][x] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

      int block_cnt;
      if (map[ny][nx] == 0)
        block_cnt = now.block + 1;
      else
        block_cnt = now.block;

      if (visited[ny][nx] == -1 || visited[ny][nx] > block_cnt) {
        visited[ny][nx] = block_cnt;
        que.push({ny, nx, block_cnt});
      }
    }
  }
}

int main() {
  cin >> n;

  map.resize(n, vector<int>(n, 0));
  visited.resize(n, vector<int>(n, -1));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < n; j++) {
      map[i][j] = temp[j] - '0';
    }
  }

  bfs(0, 0);  // 시작 점 (0, 0)

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << visited[n - 1][n - 1];

  return 0;
}