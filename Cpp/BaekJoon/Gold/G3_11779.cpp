#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const {
    if (cost > right.cost) return true;
    if (cost < right.cost) return false;

    return false;
  }
};

vector<vector<Node>> graph;
vector<int> visited;
vector<int> path;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  graph.resize(n + 1);
  visited.resize(n + 1, INT_MAX);

  path.resize(n + 1, -1);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    std::cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
  }

  int start_node, end_node;
  std::cin >> start_node >> end_node;

  priority_queue<Node> pque;
  pque.push({start_node, 0});

  visited[start_node] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.cost) continue;
    for (int i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];
      int nextcost = now.cost + next.cost;

      if (visited[next.node] != INT_MAX && nextcost >= visited[next.node])
        continue;

      visited[next.node] = nextcost;
      path[next.node] = now.node;
      pque.push({next.node, nextcost});
    }
  }

  cout << visited[end_node] << "\n";

  int node = end_node;
  vector<int> res;
  while (node != -1) {
    res.push_back(node);

    node = path[node];
  }

  cout << res.size() << "\n";

  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i] << " ";
  }

  return 0;
}