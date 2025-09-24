#include <algorithm>
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

void dijkstra(int start, vector<vector<Node>>& map, vector<int>& dist) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      int nextDist = now.dist + next.dist;

      if (dist[next.node] <= nextDist) continue;

      dist[next.node] = nextDist;
      pque.push({next.node, nextDist});
    }
  }

  return;
}

int main() {
  int TC;
  cin >> TC;

  for (int test = 0; test < TC; test++) {
    int n, m, t;  // n: node, m: edge, t: num of targets
    cin >> n >> m >> t;

    int s, g, h;
    cin >> s >> g >> h;  // s: start, g: e_node1, h: e_node2

    vector<vector<Node>> map(n + 1);
    vector<int> distS(n + 1, INT_MAX);
    vector<int> distH(n + 1, INT_MAX);
    vector<int> distG(n + 1, INT_MAX);

    int weight = 0;
    for (int i = 0; i < m; i++) {
      int from, to, cost;
      cin >> from >> to >> cost;

      if (((from == g) && (to == h)) || ((from == h) && (to == g))) {
        weight = cost;
      }

      map[from].push_back({to, cost});
      map[to].push_back({from, cost});
    }

    vector<int> targets;
    for (int i = 0; i < t; i++) {
      int temp;
      cin >> temp;

      targets.push_back(temp);
    }
    sort(targets.begin(), targets.end());

    // dijkstra from start node
    dijkstra(s, map, distS);

    // dijkstra from essential node (h)
    dijkstra(h, map, distH);

    // dijkstra from essential node (g)
    dijkstra(g, map, distG);

    for (size_t i = 0; i < targets.size(); i++) {
      int target = distS[targets[i]];

      int path1 = distS[h] + weight + distG[targets[i]];
      int path2 = distS[g] + weight + distH[targets[i]];

      if (target == path1 || target == path2) {
        cout << targets[i] << " ";
      }
    }

    cout << "\n";
  }

  return 0;
}