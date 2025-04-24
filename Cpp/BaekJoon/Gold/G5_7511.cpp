#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> parent;

int Find(int n) {
  if (parent[n] == n) return n;

  return parent[n] = Find(parent[n]);
}

void Union(int A, int B) {
  int rootA = Find(A);
  int rootB = Find(B);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;

  for (int tc = 1; tc <= test; tc++) {
    int n, k;
    cin >> n >> k;

    parent.assign(n, -1);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }

    for (int i = 0; i < k; i++) {
      int from, to;
      cin >> from >> to;

      Union(from, to);
    }

    int m;
    cin >> m;

    cout << "Scenario " << tc << ":\n";

    for (int i = 0; i < m; i++) {
      int from, to;
      cin >> from >> to;

      if (Find(from) == Find(to))
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    }

    cout << "\n";
  }

  return 0;
}