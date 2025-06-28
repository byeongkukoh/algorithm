#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<int> tree;

void build(int node, int start, int end) {
  if (start == end)
    tree[node] = start;
  else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    if (arr[tree[2 * node]] < arr[tree[2 * node + 1]]) {
      tree[node] = tree[2 * node];
    } else if (arr[tree[2 * node]] > arr[tree[2 * node + 1]]) {
      tree[node] = tree[2 * node + 1];
    } else {
      tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
  }
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    arr[idx] = val;
    tree[node] = idx;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    if (arr[tree[2 * node]] < arr[tree[2 * node + 1]]) {
      tree[node] = tree[2 * node];
    } else if (arr[tree[2 * node]] > arr[tree[2 * node + 1]]) {
      tree[node] = tree[2 * node + 1];
    } else {
      tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  build(1, 1, n);

  cin >> m;

  for (int i = 0; i < m; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      int idx, val;
      cin >> idx >> val;

      update(1, 1, n, idx, val);
    } else {
      cout << tree[1] << "\n";
    }
  }

  return 0;
}