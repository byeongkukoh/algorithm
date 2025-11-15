#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coord {
  int row;
  int col;
};

int N, M;
int min_time = INT_MAX;

vector<vector<int>> MAP;
vector<int> path;
vector<Coord> check;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs() {
  vector<vector<int>> dist;
  dist.resize(N, vector<int>(N, -1));

  queue<Coord> que;

  for (size_t i = 0; i < path.size(); i++) {
    que.push(check[path[i]]);

    dist[check[path[i]].row][check[path[i]].col] = 0;
  }

  while (!que.empty()) {
    Coord now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (MAP[ny][nx] == 1) continue;
      if (dist[ny][nx] != -1 && dist[ny][nx] <= dist[now.row][now.col] + 1)
        continue;

      que.push({ny, nx});
      dist[ny][nx] = dist[now.row][now.col] + 1;
    }
  }

  int res = INT_MIN;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (MAP[i][j] == 1) continue;
      if (dist[i][j] == -1) return -1;

      if (res < dist[i][j]) res = dist[i][j];
    }
  }

  return res;
}

void backtracking(int now, int idx) {
  if (now == M) {
    int time = bfs();

    if (time == -1) return;
    if (time < min_time) min_time = time;

    return;
  }

  for (size_t i = idx; i < check.size(); i++) {
    path.push_back(i);

    backtracking(now + 1, i + 1);

    path.pop_back();
  }

  return;
}

int main() {
  cin >> N >> M;

  MAP.resize(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> MAP[i][j];

      if (MAP[i][j] == 2) {
        check.push_back({i, j});
      }
    }
  }

  backtracking(0, 0);

  if (min_time == INT_MAX) {
    cout << -1;
    return 0;
  }

  cout << min_time;

  return 0;
}