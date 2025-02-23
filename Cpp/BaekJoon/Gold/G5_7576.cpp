#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int y, x;
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int n, m;
vector<vector<int>> box;
vector<Node> tomato;

void bfs() {
  queue<Node> que;

  for (int i = 0; i < tomato.size(); i++) {
    que.push(tomato[i]);
  }

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
      if (box[ny][nx] != 0) continue;

      que.push({ny, nx});
      box[ny][nx] = box[now.y][now.x] + 1;
    }
  }
}

int main() {
  cin >> m >> n;

  box.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];

      if (box[i][j] == 1) {
        tomato.push_back({i, j});
      }
    }
  }

  bfs();

  // cout << "\n";
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << box[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  int max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (max < box[i][j]) {
        max = box[i][j];
      }

      if (box[i][j] == 0) {
        cout << -1;
        return 0;
      }
    }
  }

  cout << max - 1;

  return 0;
}