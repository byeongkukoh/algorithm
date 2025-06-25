#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<int> max_tree;
vector<int> min_tree;

void max_build(int node, int start, int end) {
  if (start == end) {
    max_tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;

    max_build(2 * node, start, mid);
    max_build(2 * node + 1, mid + 1, end);

    max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
  }
}

int max_query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return INT_MIN;
  if (l <= start && r >= end) return max_tree[node];

  int mid = (start + end) / 2;

  int left_max = max_query(2 * node, start, mid, l, r);
  int right_max = max_query(2 * node + 1, mid + 1, end, l, r);

  return max(left_max, right_max);
}

void min_build(int node, int start, int end) {
  if (start == end) {
    min_tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;

    min_build(2 * node, start, mid);
    min_build(2 * node + 1, mid + 1, end);

    min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
  }
}

int min_query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return INT_MAX;
  if (l <= start && r >= end) return min_tree[node];

  int mid = (start + end) / 2;

  int left_min = min_query(2 * node, start, mid, l, r);
  int right_min = min_query(2 * node + 1, mid + 1, end, l, r);

  return min(left_min, right_min);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  arr.resize(n + 1, 0);
  max_tree.resize(4 * n + 1, 0);
  min_tree.resize(4 * n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i + 1];
  }

  max_build(1, 1, n);
  min_build(1, 1, n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    cout << min_query(1, 1, n, a, b) << " " << max_query(1, 1, n, a, b) << "\n";
  }

  return 0;
}