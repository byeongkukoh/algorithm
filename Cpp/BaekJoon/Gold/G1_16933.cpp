#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int cnt;
  int isNight;  // 0: 낮 | 1: 밤
};

int n, m, k;

vector<vector<int>> map;
vector<vector<vector<vector<int>>>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs() {
  queue<Node> que;
  que.push({0, 0, 0, 0});

  visited[0][0][0][0] = 1;  // visited[isNight][cnt][row][col]

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    if (now.row == n - 1 && now.col == m - 1)
      return visited[now.isNight][now.cnt][now.row][now.col];

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      int nextNight = (now.isNight + 1) % 2;

      // 벽이 아닐 때
      if (map[ny][nx] == 0 && visited[nextNight][now.cnt][ny][nx] == -1) {
        que.push({ny, nx, now.cnt, nextNight});
        visited[nextNight][now.cnt][ny][nx] =
            visited[now.isNight][now.cnt][now.row][now.col] + 1;
      }
      // 벽이고, 낮이고, 부술 수 있는 경우
      else if (map[ny][nx] == 1 && now.cnt < k && now.isNight == 0 &&
               visited[nextNight][now.cnt + 1][ny][nx] == -1) {
        que.push({ny, nx, now.cnt + 1, nextNight});
        visited[nextNight][now.cnt + 1][ny][nx] =
            visited[now.isNight][now.cnt][now.row][now.col] + 1;
      }
    }

    // 밤이면 제자리 대기
    int nextNight = (now.isNight + 1) % 2;
    if (now.isNight == 1 &&
        visited[nextNight][now.cnt][now.row][now.col] == -1) {
      que.push({now.row, now.col, now.cnt, nextNight});
      visited[nextNight][now.cnt][now.row][now.col] =
          visited[now.isNight][now.cnt][now.row][now.col] + 1;
    }
  }

  return -1;
}

int main() {
  cin >> n >> m >> k;

  map.resize(n, vector<int>(m, 0));
  // visited[isNight][cnt][row][col]
  visited.resize(2, vector<vector<vector<int>>>(
                        k + 1, vector<vector<int>>(n, vector<int>(m, -1))));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; j++) {
      map[i][j] = temp[j] - '0';
    }
  }

  int res = bfs();

  cout << res;

  return 0;
}