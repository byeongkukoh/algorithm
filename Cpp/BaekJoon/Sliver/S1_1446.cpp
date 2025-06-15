#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct NODE {
  int node;
  int dist;

  bool operator<(NODE right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

int N, D;

vector<vector<NODE>> ROAD(10000);
vector<int> dist(10000, INT_MAX);

void dijkstra(int start) {
  priority_queue<NODE> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    NODE now = pque.top();
    pque.pop();

    if (now.dist > dist[now.node]) continue;

    for (int i = 0; i < ROAD[now.node].size(); i++) {
      NODE next = ROAD[now.node][i];
      int nextDist = now.dist + next.dist;

      if (nextDist < dist[next.node]) {
        dist[next.node] = nextDist;
        pque.push({next.node, nextDist});
      }
    }

    if (now.node + 1 <= D) {
      int nextDist = now.dist + 1;

      if (nextDist < dist[now.node + 1]) {
        dist[now.node + 1] = nextDist;
        pque.push({now.node + 1, nextDist});
      }
    }
  }
}

int main() {
  cin >> N >> D;

  for (int n = 0; n < N; n++) {
    int from, to, dist;
    cin >> from >> to >> dist;

    ROAD[from].push_back({to, dist});
  }

  dijkstra(0);

  cout << dist[D];

  return 0;
}
