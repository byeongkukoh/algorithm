#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int fuel;
};

int H, W;
vector<string> MAP;
vector<vector<int>> visited;

int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(Node start) {
  queue<Node> pque;
  pque.push(start);

  visited[start.row][start.col] = 0;

  while (!pque.empty()) {
    Node now = pque.front();
    pque.pop();

    for (int i = 0; i < 8; i++) {
      // 다음 이동 좌표
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      // 연료 사용 여부 계산
      int nextFuel = now.fuel;
      if (dx[i] != 1) nextFuel += 1;

      // 못가는 경우 체크
      if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
      if (MAP[ny][nx] == '#') continue;
      if (visited[ny][nx] <= nextFuel) continue;

      pque.push({ny, nx, nextFuel});
      visited[ny][nx] = nextFuel;
    }
  }
}

int main() {
  cin >> H >> W;

  visited.assign(H, vector<int>(W, INT_MAX));

  Node start = {-1, -1, 0};
  Node finish = {-1, -1, 0};

  for (int i = 0; i < H; i++) {
    string temp;
    cin >> temp;

    MAP.push_back(temp);

    for (int j = 0; j < W; j++) {
      if (temp[j] == 'K') start = {i, j, 0};

      if (temp[j] == '*') finish = {i, j, 0};
    }
  }

  bfs(start);

  if (visited[finish.row][finish.col] == INT_MAX)
    cout << -1;
  else
    cout << visited[finish.row][finish.col];

  return 0;
}