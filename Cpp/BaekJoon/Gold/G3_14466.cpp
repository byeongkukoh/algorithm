#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int N, K, R;
// 상, 하, 좌, 우
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<Node> cows;
vector<vector<vector<bool>>> roads;
vector<vector<int>> field;

int bfs(Node start) {
  vector<vector<bool>> visited;
  visited.resize(N + 1, vector<bool>(N + 1, false));

  queue<Node> que;
  que.push(start);

  visited[start.row][start.col] = true;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
      if (visited[ny][nx]) continue;
      if (roads[now.row][now.col][i]) continue;

      que.push({ny, nx});
      visited[ny][nx] = true;
    }
  }

  int cnt = 0;
  for (int i = 0; i < K; i++) {
    Node now = cows[i];

    if (now.row == start.row && now.col == start.col) continue;

    if (!visited[now.row][now.col]) {
      cnt++;
    }
  }

  return cnt;
}

int main() {
  cin >> N >> K >> R;

  field.resize(N + 1, vector<int>(N + 1, 0));
  roads.resize(N + 1, vector<vector<bool>>(N + 1, vector<bool>(4, false)));

  // 길 체크
  for (int i = 0; i < R; i++) {
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;

    // 좌우 인접 길
    if (row1 == row2) {
      // 좌 -> 우
      if (col1 + 1 == col2) {
        roads[row1][col1][3] = true;
        roads[row2][col2][2] = true;
      } else {  // 우 -> 좌
        roads[row1][col1][2] = true;
        roads[row2][col2][3] = true;
      }
    }

    // 상하 인접 길
    if (col1 == col2) {
      // 상 -> 하
      if (row1 + 1 == row2) {
        roads[row1][col1][1] = true;
        roads[row2][col2][0] = true;
      } else {
        roads[row1][col1][0] = true;
        roads[row2][col2][1] = true;
      }
    }
  }

  // 소 위치
  for (int i = 0; i < K; i++) {
    int row, col;
    cin >> row >> col;

    cows.push_back({row, col});

    field[row][col] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < K; i++) {
    cnt += bfs(cows[i]);
  }

  cout << cnt / 2;

  return 0;
}