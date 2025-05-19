#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int cost;

  bool operator<(Node right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

vector<vector<int>> map;
vector<vector<int>> visited;

int dy[] = {1, 0};
int dx[] = {0, 1};

int n;

void bfs(int y, int x) {
  priority_queue<Node> pque;
  pque.push({y, x, 0});

  visited[y][x] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    int cnt = 0;

    if (visited[now.row][now.col] < now.cost) continue;

    for (int i = 0; i < 2; i++) {
      int nrow = now.row + dy[i];
      int ncol = now.col + dx[i];
      int cost = now.cost;

      if (nrow >= n || ncol >= n || nrow < 0 || ncol < 0) continue;
      if (map[now.row][now.col] <= map[nrow][ncol]) {
        cost = cost + (map[nrow][ncol] - map[now.row][now.col] + 1);
      }
      if (visited[nrow][ncol] <= cost) continue;

      visited[nrow][ncol] = cost;
      pque.push({nrow, ncol, cost});
    }
  }
}

int main() {
  cin >> n;

  map.resize(n, vector<int>(n, 0));
  visited.resize(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  bfs(0, 0);

  cout << visited[n - 1][n - 1];

  return 0;
}