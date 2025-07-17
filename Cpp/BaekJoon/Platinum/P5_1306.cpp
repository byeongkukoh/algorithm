#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> light;
vector<int> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = light[start];
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  int left_max = query(2 * node, start, mid, left, right);
  int right_max = query(2 * node + 1, mid + 1, end, left, right);

  return max(left_max, right_max);
}

int main() {
  cin >> N >> M;

  light.resize(N + 1, 0);
  tree.resize(4 * N + 1, 0);

  for (int i = 1; i < N + 1; i++) {
    cin >> light[i];
  }

  build(1, 1, N);

  for (int i = M; i <= N - M + 1; i++) {
    cout << query(1, 1, N, i - M + 1, i + M - 1) << " ";
  }

  return 0;
}