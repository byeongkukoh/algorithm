#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

vector<long long> arr;
vector<long long> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];  // 리프노드
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);        // 왼쪽 자식
    build(2 * node + 1, mid + 1, end);  // 오른쪽 자식

    tree[node] = tree[2 * node] + tree[2 * node + 1];  // 구간 합
  }
}

void update(int node, int start, int end, int idx, long long val) {
  if (start == end) {
    arr[idx] = val;
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid)
      update(2 * node, start, mid, idx, val);
    else
      update(2 * node + 1, mid + 1, end, idx, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

long long query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return 0;             // 겹치지 않음
  if (l <= start && r >= end) return tree[node];  // 완전 포함

  int mid = (start + end) / 2;

  long long left_sum = query(2 * node, start, mid, l, r);
  long long right_sum = query(2 * node + 1, mid + 1, end, l, r);

  return left_sum + right_sum;
}

int main() {
  cin >> n >> m >> k;

  arr.resize(n + 1, 0);
  tree.resize(4 * n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  build(1, 1, n);

  for (int i = 0; i < m + k; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {  // update
      long long idx, val;
      cin >> idx >> val;

      update(1, 1, n, idx, val);
    } else {  //  query
      int l, r;
      cin >> l >> r;

      cout << query(1, 1, n, l, r) << "\n";
    }
  }

  return 0;
}