#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<long long> arr;
vector<long long> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void update(int node, int start, int end, int idx, long long val) {
  if (start == end) {
    arr[idx] = val;
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

long long query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return 0;
  if (l <= start && r >= end) return tree[node];

  int mid = (start + end) / 2;

  long long left_sum = query(2 * node, start, mid, l, r);
  long long right_sum = query(2 * node + 1, mid + 1, end, l, r);

  return left_sum + right_sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 0);

  for (int i = 0; i < m; i++) {
    int comm;
    cin >> comm;

    if (comm == 0) {
      int l, r;
      cin >> l >> r;

      if (l > r) swap(l, r);

      cout << query(1, 1, n, l, r) << "\n";

    } else {
      long long idx, val;
      cin >> idx >> val;

      update(1, 1, n, idx, val);
    }
  }

  return 0;
}