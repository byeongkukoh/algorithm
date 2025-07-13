#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<long long> tree;

void update(int node, int start, int end, int idx, long long val) {
  if (start == end) {
    tree[node] += val;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  return;
}

long long query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  long long left_sum = query(2 * node, start, mid, left, right);
  long long right_sum = query(2 * node + 1, mid + 1, end, left, right);

  return left_sum + right_sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> Q;

  tree.resize(4 * N + 1, 0);

  for (int i = 0; i < Q; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      long long p, x;
      cin >> p >> x;

      update(1, 1, N, p, x);
    } else {
      int p, q;
      cin >> p >> q;

      cout << query(1, 1, N, p, q) << "\n";
    }
  }

  return 0;
}