#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Time {
  int upTime;
  int downTime;
};

struct Node {
  int row;
  int col;
  int time;
  int flag;  // 0: up | 1: down
};

int n, m, t, d;

vector<vector<int>> map;
vector<vector<Time>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs() {
  queue<Node> que;
  que.push({0, 0, 0, 0});  // up
  que.push({0, 0, 0, 1});  // down

  visited[0][0].upTime = 0;
  visited[0][0].downTime = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (abs(map[now.row][now.col] - map[ny][nx]) > t) continue;

      int nextTime = now.time;
      if (now.flag == 0) {
        // up
        if (map[now.row][now.col] < map[ny][nx])
          nextTime += (map[ny][nx] - map[now.row][now.col]) *
                      (map[ny][nx] - map[now.row][now.col]);
        else
          nextTime += 1;

        if (visited[ny][nx].upTime != -1 && visited[ny][nx].upTime <= nextTime)
          continue;

        visited[ny][nx].upTime = nextTime;
      } else {
        // down
        if (map[now.row][now.col] > map[ny][nx])
          nextTime += (map[now.row][now.col] - map[ny][nx]) *
                      (map[now.row][now.col] - map[ny][nx]);
        else
          nextTime += 1;

        if (visited[ny][nx].downTime != -1 &&
            visited[ny][nx].downTime <= nextTime)
          continue;

        visited[ny][nx].downTime = nextTime;
      }

      que.push({ny, nx, nextTime, now.flag});
    }
  }
}

int main() {
  cin >> n >> m >> t >> d;

  map.resize(n, vector<int>(m, 0));
  visited.resize(n, vector<Time>(m, {-1, -1}));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      if (temp[j] >= 'A' && temp[j] <= 'Z') map[i][j] = int(temp[j] - 'A');

      if (temp[j] >= 'a' && temp[j] <= 'z') map[i][j] = int(temp[j] - 'a') + 26;
    }
  }

  bfs();

  int height = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j].upTime == -1 || visited[i][j].downTime == -1) continue;

      int res = visited[i][j].upTime + visited[i][j].downTime;

      if (res <= d) height = max(height, map[i][j]);
    }
  }

  cout << height;

  return 0;
}