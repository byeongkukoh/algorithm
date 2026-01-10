#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void makeTree(int root, int N, const vector<vector<int>>& tree,
              vector<int>& parent, vector<int>& depth) {
  vector<bool> visited(N + 1, false);

  queue<int> que;
  que.push(root);

  visited[root] = true;
  parent[root] = -1;
  depth[root] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (size_t i = 0; i < tree[now].size(); i++) {
      int next = tree[now][i];

      if (visited[next]) continue;

      que.push(next);

      visited[next] = true;
      parent[next] = now;
      depth[next] = depth[now] + 1;
    }
  }
}

int lca(int node1, int node2, const vector<int>& parent,
        const vector<int>& depth) {
  // 깊이 일치 시키기
  if (depth[node1] < depth[node2]) swap(node1, node2);

  while (depth[node1] != depth[node2]) {
    node1 = parent[node1];
  }

  // 공통 부모 찾기
  while (node1 != node2) {
    node1 = parent[node1];
    node2 = parent[node2];
  }

  return node1;
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> tree(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    tree[node1].push_back(node2);
    tree[node2].push_back(node1);
  }

  vector<int> parent(N + 1, -1);
  vector<int> depth(N + 1, 0);
  makeTree(1, N, tree, parent, depth);

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    cout << lca(node1, node2, parent, depth) << "\n";
  }

  return 0;
}