#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, q;
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
    tree[node] = val;
    arr[idx] = val;
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

long long query(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 0;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  long long left_sum = query(2 * node, start, mid, left, right);
  long long right_sum = query(2 * node + 1, mid + 1, end, left, right);

  return left_sum + right_sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> q;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i + 1];
  }

  build(1, 1, n);

  for (int i = 0; i < q; i++) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;

    if (x > y) swap(x, y);

    cout << query(1, 1, n, x, y) << "\n";

    update(1, 1, n, a, b);
  }

  return 0;
}