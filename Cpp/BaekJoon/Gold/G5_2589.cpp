#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int n, m;
int max_time = 0;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<int>> map;
vector<vector<int>> visited;

void bfs(int y, int x);

int main() {
  cin >> n >> m;

  // 맵 입력
  map.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      if (temp[j] == 'W') {
        map[i][j] = 1;  // 물(이동 불가가)
      } else {
        map[i][j] = 0;  // 땅(이동 가능)
      }
    }
  }

  // bfs 완전 탐색 (flood fill)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 1) continue;

      bfs(i, j);
    }
  }

  cout << max_time;

  return 0;
}

void bfs(int y, int x) {
  visited.assign(n, vector<int>(m, -1));
  int temp_time = 0;

  queue<Node> que;
  que.push({y, x});

  visited[y][x] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (map[ny][nx] == 1) continue;
      if (visited[ny][nx] != -1 && visited[ny][nx] <= visited[now.y][now.x] + 1)
        continue;

      que.push({ny, nx});
      visited[ny][nx] = visited[now.y][now.x] + 1;

      if (visited[ny][nx] > temp_time) {
        temp_time = visited[now.y][now.x] + 1;
      }
    }
  }

  if (max_time < temp_time) {
    max_time = temp_time;
  }

  return;
}