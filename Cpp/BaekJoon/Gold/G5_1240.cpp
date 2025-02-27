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

int n, m;
vector<vector<Node>> tree;
vector<int> dist;

void bfs(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  for (int i = 0; i <= n; i++) {
    dist[i] = INT_MAX;
  }

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (now.cost > dist[now.node]) continue;

    for (int i = 0; i < tree[now.node].size(); i++) {
      Node next = tree[now.node][i];
      int nextcost = dist[now.node] + next.cost;

      if (nextcost > dist[next.node]) continue;

      dist[next.node] = nextcost;
      pque.push({next.node, nextcost});
    }
  }
}

int main() {
  cin >> n >> m;

  tree.resize(n + 1);
  dist.resize(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    tree[from].push_back({to, cost});
    tree[to].push_back({from, cost});
  }

  int de = -1;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    bfs(from);

    cout << dist[to] << "\n";
  }

  return 0;
}