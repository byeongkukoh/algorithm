#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> check;

int n, skip;
int leapCount = 0;

void checkLeap(int now) {
  if (check[now] || now == skip) return;

  check[now] = true;

  bool hasChild = false;

  for (int i = 0; i < tree[now].size(); i++) {
    int next = tree[now][i];

    if (next == skip) continue;

    hasChild = true;
    checkLeap(next);
  }

  if (!hasChild) leapCount++;

  return;
}

int main() {
  cin >> n;

  tree.resize(n);
  check.resize(n);

  int root = 0;

  for (int i = 0; i < n; i++) {
    int parent;
    cin >> parent;

    if (parent == -1) {
      root = i;
      continue;
    }

    tree[parent].push_back(i);
  }

  cin >> skip;

  checkLeap(root);

  cout << leapCount;

  return 0;
}