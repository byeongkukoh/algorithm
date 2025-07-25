#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long cost;

  bool operator<(Node right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

int n, m, k;

vector<long long> dist;
vector<vector<Node>> map;

void bfs(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 1;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.cost) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      long long ndist = now.cost + next.cost;

      if (dist[next.node] <= ndist) continue;

      pque.push({next.node, ndist});
      dist[next.node] = ndist;
    }
  }
}

int main() {
  cin >> n >> m >> k;

  map.resize(n + 1);
  dist.resize(n + 1, LLONG_MAX);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[to].push_back({from, cost});
  }

  for (int i = 0; i < k; i++) {
    int inv;
    cin >> inv;

    bfs(inv);
  }

  int city = 0;
  long long res = 0;

  for (int i = 1; i <= n; i++) {
    if (dist[i] > res) {
      city = i;
      res = dist[i];
    }
  }

  cout << city << "\n" << res;

  return 0;
}