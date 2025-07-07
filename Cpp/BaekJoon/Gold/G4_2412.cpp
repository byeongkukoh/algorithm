#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int x;
  int y;
};

bool comp(const Node left, const Node right) {
  if (left.y != right.y) return left.y < right.y;

  return left.x < right.x;
}

int n, T;
bool flag = false;
vector<Node> coord;
vector<int> dist;

void bfs() {
  queue<int> que;

  for (int i = 0; i < n; i++) {
    int x = coord[i].x;
    int y = coord[i].y;

    if (abs(x - 0) <= 2 && abs(y - 0) <= 2) {
      que.push(i);
      dist[i] = 1;
    }
  }

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    if (coord[now].y == T) {
      flag = true;
      cout << dist[now];
      return;
    }

    // 현재 x좌표의 왼쪽 탐색
    for (int i = now - 1; i >= 0; i--) {
      int nx = coord[i].x;
      int ny = coord[i].y;

      if (abs(coord[now].y - ny) > 2) break;
      if (dist[i] == -1 && abs(coord[now].x - nx) <= 2) {
        que.push(i);
        dist[i] = dist[now] + 1;
      }
    }

    // 현재 x좌표의 오른쪽 탐색
    for (int i = now + 1; i < n; i++) {
      int nx = coord[i].x;
      int ny = coord[i].y;

      if (abs(coord[now].y - ny) > 2) break;
      if (dist[i] == -1 && abs(coord[now].x - nx) <= 2) {
        que.push(i);
        dist[i] = dist[now] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> T;

  coord.resize(n, {0, 0});
  dist.resize(n, -1);

  for (int i = 0; i < n; i++) {
    cin >> coord[i].x >> coord[i].y;
  }

  sort(coord.begin(), coord.end(), comp);

  bfs();

  if (!flag) cout << -1;

  return 0;
}