#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long dist;

  bool operator<(const Node& right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

bool bfs(int n, const vector<vector<Node>>& graph, long long mid, int a, int b,
         long long c) {
  vector<long long> dist(n + 1, LLONG_MAX);

  priority_queue<Node> pque;
  pque.push({a, 0});

  dist[a] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (now.dist > dist[now.node]) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];

      if (next.dist > mid) continue;

      long long next_dist = next.dist + now.dist;

      if (next_dist > c) continue;
      if (next_dist >= dist[next.node]) continue;

      pque.push({next.node, next_dist});
      dist[next.node] = next_dist;
    }
  }

  if (dist[b] != LLONG_MAX) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n, m, a, b;
  long long c;

  cin >> n >> m >> a >> b >> c;

  vector<vector<Node>> graph(n + 1);

  int max_cost = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    long long cost;

    cin >> u >> v >> cost;

    if (cost > max_cost) max_cost = cost;

    graph[u].push_back({v, cost});
    graph[v].push_back({u, cost});
  }

  long long lo = 1;
  long long hi = max_cost;

  long long result = -1;

  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    bool res = bfs(n, graph, mid, a, b, c);

    if (res) {
      result = mid;

      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << result;

  return 0;
}