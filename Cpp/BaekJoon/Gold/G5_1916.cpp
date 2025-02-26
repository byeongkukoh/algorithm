#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int node;
  int cost;

  bool operator<(Edge right) const {
    if (cost > right.cost) return true;
    if (cost < right.cost) return false;

    return false;
  }
};

int n, m;
vector<vector<Edge>> map;
vector<int> dist;

void dijkstra(int start) {
  priority_queue<Edge> pque;
  pque.push({start, 0});
  dist[start] = 0;

  while (!pque.empty()) {
    Edge now = pque.top();
    pque.pop();

    if (now.cost > dist[now.node]) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Edge next = map[now.node][i];
      int nextcost = dist[now.node] + next.cost;

      if (nextcost >= dist[next.node]) continue;

      dist[next.node] = nextcost;
      pque.push({next.node, nextcost});
    }
  }
}

int main() {
  cin >> n >> m;

  map.resize(n + 1);  // 도시번호: 1 ~ N
  dist.resize(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[from].push_back({to, cost});
  }

  int start_node, end_node;
  cin >> start_node >> end_node;

  dijkstra(start_node);

  cout << dist[end_node];

  return 0;
}