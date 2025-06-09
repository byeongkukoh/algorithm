#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int N, M;
int res = 0;
vector<vector<int>> MAP;
vector<vector<int>> visited;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int row, int col) {
  queue<Node> que;
  que.push({row, col});

  visited[row][col] = 1;

  bool isPeak = true;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 8; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      if (MAP[ny][nx] > MAP[row][col]) isPeak = false;

      if (MAP[ny][nx] == MAP[row][col] && !visited[ny][nx]) {
        visited[ny][nx] = 1;
        que.push({ny, nx});
      }
    }
  }

  if (isPeak) res++;
}

int main() {
  cin >> N >> M;

  MAP.resize(N, vector<int>(M, 0));
  visited.resize(N, vector<int>(M, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> MAP[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == 1) continue;

      bfs(i, j);
    }
  }

  cout << res;

  return 0;
}