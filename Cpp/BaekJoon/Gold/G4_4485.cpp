#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int dist;

  bool operator<(Node right) const { return dist > right.dist; }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int map[125][125];
int visited[125][125];

int main() {
  int count = 0;
  while (1) {
    for (int i = 0; i < 125; i++) {
      for (int j = 0; j < 125; j++) {
        visited[i][j] = INT_MAX;
        map[i][j] = 0;
      }
    }

    count++;

    int n;
    cin >> n;

    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> map[i][j];
      }
    }

    priority_queue<Node> pque;
    pque.push({0, 0, map[0][0]});

    visited[0][0] = map[0][0];

    while (!pque.empty()) {
      Node now = pque.top();
      pque.pop();

      if (visited[now.y][now.x] < now.dist) continue;

      for (int i = 0; i < 4; i++) {
        int ny = now.y + dy[i];
        int nx = now.x + dx[i];
        int nextdist = now.dist + map[ny][nx];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] <= nextdist) continue;

        pque.push({ny, nx, nextdist});
        visited[ny][nx] = nextdist;
      }
    }

    cout << "Problem " << count << ": " << visited[n - 1][n - 1] << "\n";
  }

  return 0;
}