#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;
vector<int> group;

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
  cin >> n >> m;

  parent.resize(n + 1, 0);
  group.resize(n + 1, 0);

  for (int i = 0; i < n + 1; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    Union(from, to);
  }

  for (int i = 1; i < n + 1; i++) {
    group[Find(i)] = 1;
  }

  int cnt = 0;
  for (int i = 1; i < n + 1; i++) {
    if (group[i] != 0) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}