#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const { return cost > right.cost; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Node>> map;
  map.resize(n + 1);

  vector<int> visited;
  visited.resize(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[from].push_back({to, cost});
    map[to].push_back({from, cost});
  }

  int start, end;
  cin >> start >> end;

  priority_queue<Node> pque;
  pque.push({start, 0});

  visited[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.cost) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      int nextCost = now.cost + next.cost;

      if (visited[next.node] <= nextCost) continue;

      pque.push({next.node, nextCost});
      visited[next.node] = nextCost;
    }
  }

  cout << visited[end];

  return 0;
}