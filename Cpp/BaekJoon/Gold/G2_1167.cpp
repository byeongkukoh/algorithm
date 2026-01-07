#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long dist;

  bool operator<(const Node& right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

Node findFarNode(const vector<vector<Node>>& tree, int start, int N) {
  vector<long long> dist(N + 1, LLONG_MAX);

  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < tree[now.node].size(); i++) {
      int nextNode = tree[now.node][i].node;
      long long nextDist = now.dist + tree[now.node][i].dist;

      if (dist[nextNode] <= nextDist) continue;

      dist[nextNode] = nextDist;
      pque.push({nextNode, nextDist});
    }
  }

  Node farNode = {start, 0};
  for (int i = 1; i < N + 1; i++) {
    if (farNode.dist < dist[i]) farNode = {i, dist[i]};
  }

  return farNode;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<vector<Node>> tree(N + 1);
  for (int i = 0; i < N; i++) {
    int node;
    cin >> node;

    while (true) {
      int temp;
      cin >> temp;

      if (temp == -1) break;

      int dist;
      cin >> dist;

      tree[node].push_back({temp, dist});
      tree[temp].push_back({node, dist});
    }
  }

  Node rootToNode = findFarNode(tree, 1, N);
  Node nodeToNode = findFarNode(tree, rootToNode.node, N);

  cout << nodeToNode.dist;

  return 0;
}