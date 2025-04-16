#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int n, m;
int max_result = 0;

vector<vector<int>> map;
vector<vector<int>> map2;
vector<vector<int>> visited;
vector<Node> virus;

int rPath[8] = {0};
int cPath[8] = {0};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void virus_bfs(int row, int col) {
  queue<Node> que;

  for (int i = 0; i < virus.size(); i++) {
    que.push(virus[i]);
  }

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map2[ny][nx] != 0) continue;

      map2[ny][nx] = 2;
      que.push({ny, nx});
    }
  }

  return;
}

void bfs(int row, int col) {
  queue<Node> que;
  que.push({row, col});

  visited[row][col] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map2[ny][nx] != 0) continue;
      if (visited[ny][nx] != 0) continue;

      visited[ny][nx] = 1;
      que.push({ny, nx});
    }
  }

  return;
}

void backtracking(int now) {
  if (now == 3) {
    // map copy
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        map2[i][j] = map[i][j];
      }
    }

    // add wall
    for (int i = 0; i < 3; i++) {
      // cout << "{ " << rPath[i] << ", " << cPath[i] << " }\n";
      map2[rPath[i]][cPath[i]] = 1;
    }

    // start bfs
    virus_bfs(0, 0);

    visited.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map2[i][j] == 0 && visited[i][j] == 0) {
          bfs(i, j);
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j] == 1) {
          cnt++;
        }
      }
    }

    if (max_result < cnt) {
      max_result = cnt;
    }

    return;
  }

  for (int i = 0; i < n; i++) {
    if (now > 0 && rPath[now - 1] > i) continue;

    for (int j = 0; j < m; j++) {
      if (map[i][j] == 1 || map[i][j] == 2) continue;
      if (now > 0 && (rPath[now - 1] == i && cPath[now - 1] == j)) continue;
      if (now > 0 && (rPath[now - 1] == i && cPath[now - 1] > j)) continue;

      rPath[now] = i;
      cPath[now] = j;

      backtracking(now + 1);

      rPath[now] = 0;
      cPath[now] = 0;
    }
  }
}

int main() {
  cin >> n >> m;

  map.resize(n, vector<int>(m, 0));
  map2.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];

      if (map[i][j] == 2) virus.push_back({i, j});
    }
  }

  backtracking(0);

  cout << max_result;

  return 0;
}