#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> arr;
vector<int> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}

int query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return INT_MAX;
  if (l <= start && r >= end) return tree[node];

  int mid = (start + end) / 2;

  int left_min = query(2 * node, start, mid, l, r);
  int right_min = query(2 * node + 1, mid + 1, end, l, r);

  return min(left_min, right_min);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i + 1];
  }

  build(1, 1, n);

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;

    if (l > r) swap(l, r);

    cout << query(1, 1, n, l, r) << "\n";
  }

  return 0;
}