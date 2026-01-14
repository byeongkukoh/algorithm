#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int min_value;
  int max_value;
};

void build(const vector<int>& arr, vector<Node>& segtree, int node, int start,
           int end) {
  if (start == end) {
    segtree[node].min_value = arr[start];
    segtree[node].max_value = arr[start];
  } else {
    int mid = (start + end) / 2;

    build(arr, segtree, 2 * node, start, mid);
    build(arr, segtree, 2 * node + 1, mid + 1, end);

    segtree[node].min_value =
        min(segtree[2 * node].min_value, segtree[2 * node + 1].min_value);
    segtree[node].max_value =
        max(segtree[2 * node].max_value, segtree[2 * node + 1].max_value);
  }
}

Node query(const vector<Node>& segtree, int node, int start, int end, int left,
           int right) {
  if (end < left || start > right) return {INT_MAX, INT_MIN};

  if (left <= start && right >= end) return segtree[node];

  int mid = (start + end) / 2;

  Node l = query(segtree, node * 2, start, mid, left, right);
  Node r = query(segtree, node * 2 + 1, mid + 1, end, left, right);

  return {min(l.min_value, r.min_value), max(l.max_value, r.max_value)};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> arr(N + 1, -1);
  vector<Node> segtree(4 * N + 1, {-1, -1});

  for (int i = 0; i < N; i++) {
    cin >> arr[i + 1];
  }

  build(arr, segtree, 1, 1, N);

  for (int i = 0; i < M; i++) {
    int left, right;
    cin >> left >> right;

    Node result = query(segtree, 1, 1, N, left, right);

    cout << result.min_value << " " << result.max_value << "\n";
  }

  return 0;
}

// #include <algorithm>
// #include <climits>
// #include <iostream>
// #include <vector>

// using namespace std;

// int n, m;
// vector<int> arr;
// vector<int> max_tree;
// vector<int> min_tree;

// void max_build(int node, int start, int end) {
//   if (start == end) {
//     max_tree[node] = arr[start];
//   } else {
//     int mid = (start + end) / 2;

//     max_build(2 * node, start, mid);
//     max_build(2 * node + 1, mid + 1, end);

//     max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
//   }
// }

// int max_query(int node, int start, int end, int l, int r) {
//   if (r < start || l > end) return INT_MIN;
//   if (l <= start && r >= end) return max_tree[node];

//   int mid = (start + end) / 2;

//   int left_max = max_query(2 * node, start, mid, l, r);
//   int right_max = max_query(2 * node + 1, mid + 1, end, l, r);

//   return max(left_max, right_max);
// }

// void min_build(int node, int start, int end) {
//   if (start == end) {
//     min_tree[node] = arr[start];
//   } else {
//     int mid = (start + end) / 2;

//     min_build(2 * node, start, mid);
//     min_build(2 * node + 1, mid + 1, end);

//     min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
//   }
// }

// int min_query(int node, int start, int end, int l, int r) {
//   if (r < start || l > end) return INT_MAX;
//   if (l <= start && r >= end) return min_tree[node];

//   int mid = (start + end) / 2;

//   int left_min = min_query(2 * node, start, mid, l, r);
//   int right_min = min_query(2 * node + 1, mid + 1, end, l, r);

//   return min(left_min, right_min);
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   cin >> n >> m;

//   arr.resize(n + 1, 0);
//   max_tree.resize(4 * n + 1, 0);
//   min_tree.resize(4 * n + 1, 0);

//   for (int i = 0; i < n; i++) {
//     cin >> arr[i + 1];
//   }

//   max_build(1, 1, n);
//   min_build(1, 1, n);

//   for (int i = 0; i < m; i++) {
//     int a, b;
//     cin >> a >> b;

//     if (a > b) swap(a, b);

//     cout << min_query(1, 1, n, a, b) << " " << max_query(1, 1, n, a, b) <<
//     "\n";
//   }

//   return 0;
// }