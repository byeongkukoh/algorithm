#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int n;
vector<vector<int>> board;
vector<vector<int>> visited;

int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs(Node start) {
  queue<Node> que;
  que.push(start);

  board[start.row][start.col] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 8; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (board[ny][nx] != 0) continue;
      if (board[ny][nx] != 0 && board[ny][nx] <= board[now.row][now.col] + 1)
        continue;

      board[ny][nx] = board[now.row][now.col] + 1;
      que.push({ny, nx});
    }
  }
}

int main() {
  int test;
  cin >> test;
  for (int t = 0; t < test; t++) {
    cin >> n;

    board.assign(n, vector<int>(n, 0));

    Node start;
    Node goal;

    cin >> start.row >> start.col;
    cin >> goal.row >> goal.col;

    bfs(start);

    cout << board[goal.row][goal.col] - 1 << "\n";
  }

  return 0;
}