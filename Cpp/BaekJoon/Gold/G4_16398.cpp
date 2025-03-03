#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int start, end, weight;

  bool operator<(Node right) const {
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
  int n;
  cin >> n;

  vector<vector<int>> map;
  map.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      mst.push_back({i, j, map[i][j]});
    }
  }

  sort(mst.begin(), mst.end());

  parent.resize(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  long long sum = 0;
  for (int i = 0; i < mst.size(); i++) {
    Node now = mst[i];

    if (Find(now.start) == Find(now.end)) continue;

    Union(now.start, now.end);

    sum += now.weight;
  }

  cout << sum;

  return 0;
}