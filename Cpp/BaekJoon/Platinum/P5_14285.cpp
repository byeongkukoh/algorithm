#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;
};

struct QNode {
  int node;
  int total;
  int max_dist;
  int value;

  bool operator<(QNode right) const {
    if (value != right.value) return value > right.value;

    return false;
  }
};

int n, m;
vector<vector<Node>> graph;
vector<int> dist;
vector<int> max_value;
vector<int> total_value;

void dijkstra(int start) {
  priority_queue<QNode> pque;
  pque.push({start, 0, 0, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    QNode now = pque.top();
    pque.pop();

    if (dist[now.node] < now.value) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];

      int next_total = now.total + next.dist;
      int next_max = now.max_dist;

      if (now.max_dist < next.dist) next_max = next.dist;

      int next_value = next_total - next_max;

      if (dist[next.node] <= next_value) continue;

      pque.push({next.node, next_total, next_max, next_value});
      dist[next.node] = next_value;
      max_value[next.node] = next_max;
      total_value[next.node] = next_total;
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  dist.resize(n + 1, INT_MAX);
  max_value.resize(n + 1, 0);
  total_value.resize(n + 1, 0);

  int total_dist = 0;

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});

    total_dist += cost;
  }

  int start, end;
  cin >> start >> end;

  dijkstra(start);

  cout << total_dist - total_value[end] + max_value[end];

  return 0;
}