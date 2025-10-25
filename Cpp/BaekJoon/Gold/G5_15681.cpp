#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> treeSize;

void makeTree(int node, int pNode) {
  for (size_t i = 0; i < graph[node].size(); i++) {
    int curr = graph[node][i];

    if (curr != pNode) {
      tree[node].push_back(curr);
      makeTree(curr, node);
    }
  }
}

void countSubtreeNodes(int node) {
  treeSize[node] = 1;

  for (size_t i = 0; i < tree[node].size(); i++) {
    int curr = tree[node][i];

    countSubtreeNodes(curr);

    treeSize[node] += treeSize[curr];
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, root, query;
  cin >> N >> root >> query;

  graph.resize(N + 1);
  tree.resize(N + 1);
  treeSize.resize(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int n1, n2;
    cin >> n1 >> n2;

    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  makeTree(root, -1);
  countSubtreeNodes(root);

  for (int i = 0; i < query; i++) {
    int node;
    cin >> node;

    cout << treeSize[node] << "\n";
  }

  return 0;
}