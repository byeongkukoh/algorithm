#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int n, m;
int max_area = 0;

vector<vector<int>> pic;
vector<vector<int>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x});

  visited[y][x] = 1;
  int temp = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (visited[ny][nx] == 1) continue;
      if (pic[ny][nx] == 0) continue;

      visited[ny][nx] = 1;
      que.push({ny, nx});
      temp++;
    }
  }

  if (max_area < temp) {
    max_area = temp;
  }
}

int main() {
  cin >> n >> m;

  pic.resize(n, vector<int>(m, 0));
  visited.assign(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> pic[i][j];
    }
  }

  int pic_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (pic[i][j] == 0) continue;
      if (visited[i][j] == 1) continue;

      pic_cnt++;
      bfs(i, j);
    }
  }

  cout << pic_cnt << "\n";
  cout << max_area;

  return 0;
}