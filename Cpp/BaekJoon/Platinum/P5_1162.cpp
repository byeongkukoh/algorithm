#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long cost;
  int wrap;

  bool operator<(Node right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

struct Length {
  int node;
  long long cost;
};

int n, m, k;
vector<vector<Length>> road;
vector<vector<long long>> dist;

void bfs(int start) {
  priority_queue<Node> pque;
  pque.push({start, 0, 0});

  dist[0][start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.wrap][now.node] < now.cost) continue;

    for (size_t i = 0; i < road[now.node].size(); i++) {
      int next = road[now.node][i].node;
      long long nextDist = now.cost + road[now.node][i].cost;

      if (dist[now.wrap][next] > nextDist) {
        pque.push({next, nextDist, now.wrap});
        dist[now.wrap][next] = nextDist;
      }

      // K개 미만으로 포장했을 떄,
      if (now.wrap < k) {
        nextDist = now.cost;

        if (dist[now.wrap + 1][next] > nextDist) {
          pque.push({next, nextDist, now.wrap + 1});
          dist[now.wrap + 1][next] = nextDist;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;

  road.resize(n + 1);
  dist.resize(k + 1, vector<long long>(n + 1, LLONG_MAX));

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    road[from].push_back({to, cost});
    road[to].push_back({from, cost});
  }

  bfs(1);

  long long res = LLONG_MAX;

  for (int i = 0; i <= k; i++) {
    if (res > dist[i][n]) res = dist[i][n];
  }

  cout << res;

  return 0;
}