#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

int n;
vector<vector<char>> map;
vector<vector<int>> visited1;
vector<vector<int>> visited2;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<Node> que;
  que.push({y, x});

  visited1[y][x] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (visited1[ny][nx] == 1) continue;
      if (map[now.y][now.x] != map[ny][nx]) continue;

      visited1[ny][nx] = 1;
      que.push({ny, nx});
    }
  }
}

void bfs2(int y, int x) {
  queue<Node> que;
  que.push({y, x});

  visited2[y][x] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (visited2[ny][nx] == 1) continue;

      if (map[now.y][now.x] == 'G' || map[now.y][now.x] == 'R') {
        if (map[ny][nx] == 'B') continue;

        visited2[ny][nx] = 1;
        que.push({ny, nx});
      } else {
        if (map[now.y][now.x] != map[ny][nx]) continue;

        visited2[ny][nx] = 1;
        que.push({ny, nx});
      }

      visited2[ny][nx] = 1;
      que.push({ny, nx});
    }
  }
}

int main() {
  cin >> n;

  map.resize(n, vector<char>(n, 'a'));
  visited1.resize(n, vector<int>(n, 0));
  visited2.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < n; j++) {
      map[i][j] = temp[j];
    }
  }

  int cnt1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited1[i][j] == 0) {
        cnt1++;
        bfs(i, j);
      }
    }
  }

  cout << cnt1 << " ";

  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited2[i][j] == 0) {
        cnt2++;
        bfs2(i, j);
      }
    }
  }

  cout << cnt2;

  return 0;
}