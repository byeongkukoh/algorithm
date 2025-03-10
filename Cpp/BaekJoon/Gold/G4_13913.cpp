#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int b_node;
  int dist;
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<Node> dist;

  dist.resize(200000, {-1, -1, -1});

  dist[n] = {n, -1, 0};

  queue<Node> que;
  que.push(dist[n]);

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 3; i++) {
      int nextnode = now.node;

      if (i == 0) nextnode += 1;
      if (i == 1) nextnode -= 1;
      if (i == 2) nextnode *= 2;

      if (nextnode < 0 || nextnode >= 200000) continue;

      int nextdist = now.dist + 1;

      if (dist[nextnode].dist != -1 && nextdist >= dist[nextnode].dist)
        continue;

      dist[nextnode] = {nextnode, now.node, nextdist};
      que.push({nextnode, now.node, nextdist});
    }
  }

  cout << dist[k].dist << "\n";

  vector<int> res;
  int node = dist[k].node;
  while (node != -1) {
    res.push_back(node);

    node = dist[node].b_node;
  }

  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i] << " ";
  }

  return 0;
}