#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int life;

  bool operator<(const Node& other) const {
    if (life != other.life) return life > other.life;

    return false;
  }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<int>> map(501, vector<int>(501, 0));
vector<vector<int>> use_life(501, vector<int>(501, INT_MAX));

void dijkstra(int row, int col) {
  priority_queue<Node> pque;
  pque.push({row, col, 0});

  use_life[row][col] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (use_life[now.row][now.col] < now.life) continue;

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny > 500 || nx < 0 || nx > 500) continue;
      if (map[ny][nx] == 2) continue;

      int nLife = now.life + map[ny][nx];

      if (use_life[ny][nx] <= nLife) continue;

      pque.push({ny, nx, nLife});
      use_life[ny][nx] = nLife;
    }
  }
}

int main() {
  // 위험한 구역: 1
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        map[y][x] = 1;
      }
    }
  }

  // 죽음의 구역: 2
  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        map[y][x] = 2;
      }
    }
  }

  dijkstra(0, 0);

  if (use_life[500][500] == INT_MAX) {
    cout << -1;
    return 0;
  } else {
    cout << use_life[500][500];
    return 0;
  }
}