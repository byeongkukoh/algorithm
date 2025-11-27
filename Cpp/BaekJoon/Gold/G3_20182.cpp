#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;
};

struct Node2 {
  int node;
  int max_cost;
  int cost;

  bool operator<(Node2 right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

int n, m;
vector<vector<Node>> graph;
vector<vector<int>> dist;

void bfs(int start, int max_cost) {
  priority_queue<Node2> pque;
  pque.push({start, 0, 0});

  dist[0][start] = 0;

  while (!pque.empty()) {
    Node2 now = pque.top();
    pque.pop();

    if (dist[now.max_cost][now.node] < now.cost) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      int next = graph[now.node][i].node;
      int nextCost = graph[now.node][i].cost + now.cost;

      if (nextCost > max_cost) continue;

      int nextMaxCost = now.max_cost;

      if (nextMaxCost < graph[now.node][i].cost)
        nextMaxCost = graph[now.node][i].cost;
      if (dist[nextMaxCost][next] <= nextCost) continue;

      pque.push({next, nextMaxCost, nextCost});
      dist[nextMaxCost][next] = nextCost;
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  dist.resize(21, vector<int>(n + 1, INT_MAX));

  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  bfs(a, c);

  for (int i = 0; i < 21; i++) {
    if (dist[i][b] > c) continue;

    cout << i;
    return 0;
  }

  cout << -1;

  return 0;
}