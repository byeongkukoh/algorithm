#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int n, m;

vector<vector<int>> map;
vector<vector<int>> dist;
vector<Node> school;
vector<Node> home;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<int> path;
vector<int> visited;

int distSum = INT_MAX;

void bfs() {
  queue<Node> que;

  for (int i = 0; i < m; i++) {
    int idx = path[i];
    que.push(school[idx]);

    dist[school[idx].y][school[idx].x] = 1;
  }

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

      int nextdist = dist[now.y][now.x] + 1;

      if (dist[ny][nx] == 0 || dist[ny][nx] > nextdist) {
        dist[ny][nx] = nextdist;
        que.push({ny, nx});
      }
    }
  }
}

void func(int now) {
  if (now == m) {
    dist.assign(n, vector<int>(n, 0));

    bfs();

    int tempDist = 0;
    for (int i = 0; i < home.size(); i++) {
      tempDist += dist[home[i].y][home[i].x] - 1;
    }

    if (tempDist < distSum) distSum = tempDist;

    return;
  }

  for (int i = 0; i < school.size(); i++) {
    if (visited[i] == 1) continue;
    if (now > 0 && path[now - 1] > i) continue;

    path.push_back(i);
    visited[i] = 1;

    func(now + 1);

    path.pop_back();
    visited[i] = 0;
  }
}

int main() {
  cin >> n >> m;

  map.assign(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];

      if (map[i][j] == 1) {
        home.push_back({i, j});
      }

      if (map[i][j] == 2) {
        school.push_back({i, j});
      }
    }
  }

  visited.assign(school.size(), 0);

  func(0);

  cout << distSum;

  return 0;
}