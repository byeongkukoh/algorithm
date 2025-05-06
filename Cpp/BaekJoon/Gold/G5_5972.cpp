#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

vector<vector<Node>> map;
vector<int> visited;

void dijkstra(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  visited[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.cost) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      int next = map[now.node][i].node;
      int nextCost = now.cost + map[now.node][i].cost;

      if (visited[next] <= nextCost) continue;

      visited[next] = nextCost;
      pque.push({next, nextCost});
    }
  }

  return;
}

int main() {
  int n, m;
  cin >> n >> m;

  map.resize(n + 1);
  visited.resize(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[from].push_back({to, cost});
    map[to].push_back({from, cost});
  }

  dijkstra(1);

  cout << visited[n];

  return 0;
}