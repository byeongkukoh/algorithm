#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

int N, M, X, Y;

vector<int> dist;
vector<vector<Node>> map;

void bfs(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      int nextDist = now.dist + next.dist;

      if (dist[next.node] <= nextDist) continue;

      pque.push({next.node, nextDist});
      dist[next.node] = nextDist;
    }
  }
}

int main() {
  cin >> N >> M >> X >> Y;

  map.resize(N + 1);
  dist.resize(N + 1, INT_MAX);

  for (int i = 0; i < M; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[from].push_back({to, cost});
    map[to].push_back({from, cost});
  }

  bfs(Y);

  sort(dist.begin(), dist.end());

  if (dist[N - 1] == INT_MAX || dist[N - 1] * 2 > X) {
    cout << -1;
  } else {
    int days = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
      if (cnt + dist[i] * 2 <= X) {
        cnt += dist[i] * 2;
      } else {
        ++days;
        cnt = dist[i] * 2;
      }
    }

    cout << ++days;
  }

  return 0;
}