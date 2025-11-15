#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(const Node& right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

vector<int> dist;

vector<vector<Node>> graph;

int n, m;
int x, y, z;

void bfs(int start, int end, bool type) {
  dist.assign(n + 1, INT_MAX);

  priority_queue<Node> pque;
  pque.push({start, 0});
  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (now.cost > dist[now.node]) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      int next = graph[now.node][i].node;
      int nextCost = graph[now.node][i].cost + now.cost;

      if (type && next == y) continue;
      if (dist[next] <= nextCost) continue;

      pque.push({next, nextCost});
      dist[next] = nextCost;
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back({v, w});
  }

  cin >> x >> y >> z;

  bfs(x, y, false);
  if (dist[y] == INT_MAX) {
    cout << -1 << " ";
  } else {
    int temp = dist[y];
    bfs(y, z, false);

    if (dist[z] == INT_MAX) {
      cout << -1 << " ";
    } else {
      cout << temp + dist[z] << " ";
    }
  }

  bfs(x, z, true);
  if (dist[z] == INT_MAX) {
    cout << -1;
  } else {
    cout << dist[z];
  }

  return 0;
}