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

int n, m, r;
vector<vector<Node>> ground;
vector<int> dist;
vector<int> items;

void bfs(int start) {
  dist.clear();
  dist.assign(n + 1, INT_MAX);

  priority_queue<Node> pque;
  pque.push({start, 0});
  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < ground[now.node].size(); i++) {
      int next = ground[now.node][i].node;
      int nextDist = ground[now.node][i].dist + now.dist;

      if (dist[next] <= nextDist) continue;

      pque.push({next, nextDist});
      dist[next] = nextDist;
    }
  }
}

int main() {
  cin >> n >> m >> r;

  ground.resize(n + 1);
  items.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> items[i];
  }

  for (int i = 0; i < r; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    ground[from].push_back({to, cost});
    ground[to].push_back({from, cost});
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bfs(i);

    int temp = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[j] <= m) temp += items[j];
    }

    if (temp > ans) ans = temp;
  }

  cout << ans;

  return 0;
}