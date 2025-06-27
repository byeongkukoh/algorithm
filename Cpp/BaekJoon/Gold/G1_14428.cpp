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

int query(int node, int start, int end, int l, int r) {
  if (l > end || r < start) return 0;
  if (l <= start && r >= end) return tree[node];

  int mid = (start + end) / 2;

  int left_idx = query(2 * node, start, mid, l, r);
  int right_idx = query(2 * node + 1, mid + 1, end, l, r);

  if (left_idx == 0) return right_idx;
  if (right_idx == 0) return left_idx;

  if (arr[left_idx] < arr[right_idx]) {
    return left_idx;
  } else if (arr[left_idx] > arr[right_idx]) {
    return right_idx;
  } else {
    return min(left_idx, right_idx);
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
      int left, right;
      cin >> left >> right;

      if (left > right) swap(left, right);

      cout << query(1, 1, n, left, right) << "\n";
    }
  }

  return 0;
}