#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> cost;

int Find(int n) {
  if (parent[n] == n) return n;

  return parent[n] = Find(parent[n]);
}

void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);

  if (rootA == rootB) return;

  if (cost[rootA] < cost[rootB]) {
    parent[rootB] = rootA;
  } else {
    parent[rootA] = rootB;
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cost.resize(n + 1, 0);
  parent.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int f1, f2;
    cin >> f1 >> f2;

    Union(f1, f2);
  }

  vector<bool> isRoot;
  isRoot.resize(n + 1, false);

  for (int i = 1; i <= n; i++) {
    int root = Find(i);

    if (isRoot[root])
      continue;
    else
      isRoot[root] = true;
  }

  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (isRoot[i]) {
      result += cost[i];
    }
  }

  if (result <= k) {
    cout << result;
  } else {
    cout << "Oh no";
  }

  return 0;
}