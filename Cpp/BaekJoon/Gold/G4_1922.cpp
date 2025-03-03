#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int start, end, weight;

  bool operator<(Node right) {
    if (weight < right.weight) return true;
    if (weight > right.weight) return false;

    if (start < right.start) return true;
    if (start > right.start) return false;

    if (end < right.end) return true;
    if (end > right.end) return false;

    return false;
  }
};

vector<int> parent;
vector<Node> mst;

int Find(int n) {
  if (n == parent[n]) return n;

  return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
  int rootA = Find(a);
  int rootB = Find(b);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    mst.push_back({from, to, cost});
  }

  sort(mst.begin(), mst.end());

  parent.resize(n + 1);
  for (int i = 0; i < n + 1; i++) {
    parent[i] = i;
  }

  int sum = 0;
  for (int i = 0; i < m; i++) {
    Node now = mst[i];

    if (Find(now.start) == Find(now.end)) continue;

    Union(now.start, now.end);

    sum += now.weight;
  }

  cout << sum;

  return 0;
}