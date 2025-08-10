#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

int n, m;
vector<vector<Node>> store;
vector<vector<long long>> dist;  // n번 집하장에서 출발할 때의 최단거리
vector<vector<int>> table;

void bfs(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start][start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[start][now.node] < now.dist) continue;

    for (size_t i = 0; i < store[now.node].size(); i++) {
      int next = store[now.node][i].node;
      int nextDist = now.dist + store[now.node][i].dist;

      if (dist[start][next] <= nextDist) continue;

      pque.push({next, nextDist});
      dist[start][next] = nextDist;

      if (now.node == start) {
        table[start][next] = next;
      } else {
        table[start][next] = table[start][now.node];
      }
    }
  }
}

int main() {
  cin >> n >> m;
  store.resize(n + 1);
  dist.resize(n + 1, vector<long long>(n + 1, INT_MAX));
  table.resize(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    store[from].push_back({to, cost});
    store[to].push_back({from, cost});
  }

  for (int i = 1; i <= n; i++) {
    bfs(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        cout << '-';
      } else {
        cout << table[i][j];
      }

      cout << " ";
    }
    cout << "\n";
  }

  return 0;
}