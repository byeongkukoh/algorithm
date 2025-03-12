#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

vector<vector<int>> map;

int main() {
  int n;
  cin >> n;

  map.resize(n, vector<int>(n, 0));

  Node start, end;
  cin >> start.row >> start.col >> end.row >> end.col;

  int dy[] = {-2, -2, 0, 0, 2, 2};
  int dx[] = {-1, 1, -2, 2, -1, 1};

  queue<Node> que;
  que.push(start);

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 6; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (map[ny][nx] != 0 && map[ny][nx] <= map[now.row][now.col] + 1)
        continue;

      map[ny][nx] = map[now.row][now.col] + 1;

      que.push({ny, nx});
    }
  }

  if (map[end.row][end.col] == 0) {
    cout << -1;
  } else {
    cout << map[end.row][end.col];
  }

  return 0;
}