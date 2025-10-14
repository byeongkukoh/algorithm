#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int check;
  int dir;

  bool operator<(Node right) const {
    if (check != right.check) return check > right.check;

    return false;
  }
};

int n;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

Node start = {-1, -1}, fin = {-1, -1};
vector<vector<int>> map;
vector<vector<vector<int>>> dist;

void bfs() {
  dist.resize(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));

  priority_queue<Node> pque;

  for (int i = 0; i < 4; i++) {
    dist[start.y][start.x][i] = 0;
    pque.push({start.y, start.x, 0, i});
  }

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (now.check > dist[now.y][now.x][now.dir]) continue;

    int ny = now.y + dy[now.dir];
    int nx = now.x + dx[now.dir];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if (map[ny][nx] == 1) continue;

    if (dist[ny][nx][now.dir] > now.check) {
      pque.push({ny, nx, now.check, now.dir});
      dist[ny][nx][now.dir] = now.check;
    }

    if (map[ny][nx] == 2) {
      int ndir1 = (now.dir + 1) % 4;
      if (dist[ny][nx][ndir1] > now.check + 1) {
        dist[ny][nx][ndir1] = now.check + 1;
        pque.push({ny, nx, now.check + 1, ndir1});
      }
      int ndir2 = (now.dir + 3) % 4;
      if (dist[ny][nx][ndir2] > now.check + 1) {
        dist[ny][nx][ndir2] = now.check + 1;
        pque.push({ny, nx, now.check + 1, ndir2});
      }
    }
  }

  return;
}

int main() {
  cin >> n;

  map.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < n; j++) {
      if (temp[j] == '*') map[i][j] = 1;  // 벽

      if (temp[j] == '.') map[i][j] = 0;  // 이동 가능

      if (temp[j] == '!') map[i][j] = 2;  // 거울 설치 가능

      if (temp[j] == '#') {
        map[i][j] = 0;

        if (start.x == -1) {
          start.y = i;
          start.x = j;
          start.check = 0;
          start.dir = 0;
        } else {
          fin.y = i;
          fin.x = j;
          fin.check = 0;
          fin.dir = 0;
        }
      }
    }
  }

  bfs();

  int result = INT_MAX;
  for (int i = 0; i < 4; i++) {
    if (dist[fin.y][fin.x][i] < result) {
      result = dist[fin.y][fin.x][i];
    }
  }

  cout << result;

  return 0;
}