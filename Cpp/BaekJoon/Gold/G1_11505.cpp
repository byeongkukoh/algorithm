#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start] % 1000000007;
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] * tree[2 * node + 1] % 1000000007;
  }
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    tree[node] = val;
    arr[idx] = val;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node] = tree[2 * node] * tree[2 * node + 1] % 1000000007;
  }
}

long long query(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 1;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  long long left_multi = query(2 * node, start, mid, left, right);
  long long right_multi = query(2 * node + 1, mid + 1, end, left, right);

  return left_multi * right_multi % 1000000007;
}

int main() {
  cin >> n >> m >> k;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 1);

  for (int i = 0; i < n; i++) {
    cin >> arr[i + 1];
  }

  build(1, 1, n);

  for (int i = 0; i < m + k; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      int b, c;
      cin >> b >> c;

      update(1, 1, n, b, c);
    } else {
      int b, c;
      cin >> b >> c;

      if (b > c) swap(b, c);

      cout << query(1, 1, n, b, c) << "\n";
    }
  }

  return 0;
}