#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<int> arr;
vector<int> tree;

int sign(int val) {
  if (val < 0) return -1;
  if (val > 0) return 1;

  return 0;
}

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = sign(arr[start]);
    return;
  }

  int mid = (start + end) / 2;

  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);

  tree[node] = tree[2 * node] * tree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    arr[idx] = sign(val);
    tree[node] = sign(val);

    return;
  }

  int mid = (start + end) / 2;

  if (idx <= mid) {
    update(2 * node, start, mid, idx, val);
  } else {
    update(2 * node + 1, mid + 1, end, idx, val);
  }

  tree[node] = tree[2 * node] * tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 1;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  int qleft = query(2 * node, start, mid, left, right);
  int qright = query(2 * node + 1, mid + 1, end, left, right);

  return qleft * qright;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> k) {
    arr.resize(n + 1, 0);
    tree.resize(4 * n + 1, 1);

    for (int i = 1; i < n + 1; i++) {
      cin >> arr[i];
    }

    build(1, 1, n);

    for (int i = 0; i < k; i++) {
      char comm;
      cin >> comm;

      if (comm == 'C') {
        int idx, val;
        cin >> idx >> val;

        update(1, 1, n, idx, val);
      } else {
        int left, right;
        cin >> left >> right;

        int res = query(1, 1, n, left, right);

        if (res < 0) {
          cout << "-";
        } else if (res == 0) {
          cout << 0;
        } else {
          cout << "+";
        }
      }
    }

    cout << "\n";
  }

  return 0;
}