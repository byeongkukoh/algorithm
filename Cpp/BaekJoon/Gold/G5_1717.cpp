#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n + 1; i++) {
    parent.push_back(i);
  }

  for (int i = 0; i < m; i++) {
    int comm, a, b;
    cin >> comm >> a >> b;

    if (comm == 0) {
      Union(a, b);
    }

    if (comm == 1) {
      int rootA = Find(a);
      int rootB = Find(b);

      if (rootA == rootB)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }

  return 0;
}