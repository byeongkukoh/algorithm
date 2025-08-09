#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

int V, E, P;

vector<vector<Node>> map;
vector<int> mdist;  // 집 -> 마산 최단경로 (민준)
vector<int> gdist;  // P -> 집 & P -> 마산 최단경로 (건우)

void bfs(int start, vector<int>& dist) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < map[now.node].size(); i++) {
      int next = map[now.node][i].node;
      int nextDist = now.dist + map[now.node][i].dist;

      if (dist[next] < nextDist) continue;

      pque.push({next, nextDist});
      dist[next] = nextDist;
    }
  }
}

int main() {
  cin >> V >> E >> P;

  if (V == P || P == 1) {
    cout << "SAVE HIM";
    return 0;
  }

  map.resize(V + 1);
  gdist.resize(V + 1, INT_MAX);
  mdist.resize(V + 1, INT_MAX);

  for (int i = 0; i < E; i++) {
    int from, to, dist;
    cin >> from >> to >> dist;

    map[from].push_back({to, dist});
    map[to].push_back({from, dist});
  }

  // 민준 최단경로
  bfs(1, mdist);
  int minjun = mdist[V];

  // 건우 최단경로
  bfs(P, gdist);
  int gunwoo = gdist[1] + gdist[V];

  if (gunwoo == minjun) {
    cout << "SAVE HIM";
  } else {
    cout << "GOOD BYE";
  }

  return 0;
}