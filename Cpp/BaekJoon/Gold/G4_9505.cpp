#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int time;

  bool operator<(Node right) const { return time > right.time; }
};

int k, w, h;
int clingOn[26] = {0};  // A: 0 ~ Z: 25
vector<vector<int>> map;
vector<vector<int>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    cin >> k >> w >> h;

    map.assign(h, vector<int>(w, 0));
    visited.assign(h, vector<int>(w, INT_MAX));

    fill(clingOn, clingOn + 26, 0);

    for (int i = 0; i < k; i++) {
      char num;
      int time;
      cin >> num >> time;

      clingOn[num - 'A'] = time;
    }

    Node start;

    for (int i = 0; i < h; i++) {
      string temp;
      cin >> temp;

      for (int j = 0; j < w; j++) {
        if (temp[j] == 'E') {
          start.x = j;
          start.y = i;
          start.time = 0;
        }
        map[i][j] = clingOn[temp[j] - 'A'];
      }
    }

    if (start.x == 0 || start.x == w - 1 || start.y == 0 || start.y == h - 1) {
      cout << 0 << "\n";
      continue;
    }

    int exit_time = INT_MAX;

    priority_queue<Node> pque;
    pque.push(start);

    visited[start.y][start.x] = start.time;

    while (!pque.empty()) {
      Node now = pque.top();
      pque.pop();

      if (visited[now.y][now.x] < now.time) continue;

      for (int i = 0; i < 4; i++) {
        int ny = now.y + dy[i];
        int nx = now.x + dx[i];

        if (ny >= h || nx >= w || ny < 0 || nx < 0) continue;

        int nexttime = now.time + map[ny][nx];
        if (visited[ny][nx] <= nexttime) continue;

        pque.push({ny, nx, nexttime});
        visited[ny][nx] = nexttime;

        if (ny == 0 || ny == h - 1 || nx == 0 || nx == w - 1) {
          if (exit_time > visited[ny][nx]) {
            exit_time = visited[ny][nx];
          }
        }
      }
    }

    cout << exit_time << '\n';
  }

  return 0;
}