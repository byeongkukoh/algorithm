#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> height;
vector<int> tree;  // 인덱스 저장

int getMinIndex(int leftIdx, int rightIdx) {
  if (leftIdx == -1) return rightIdx;
  if (rightIdx == -1) return leftIdx;

  if (height[leftIdx] <= height[rightIdx]) return leftIdx;

  return rightIdx;
}

int build(int node, int start, int end) {
  if (start == end) return tree[node] = start;

  int mid = (start + end) / 2;

  int leftIdx = build(2 * node, start, mid);
  int rightIdx = build(2 * node + 1, mid + 1, end);

  return tree[node] = getMinIndex(leftIdx, rightIdx);
}

int query(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return -1;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  int leftIdx = query(2 * node, start, mid, left, right);
  int rightIdx = query(2 * node + 1, mid + 1, end, left, right);

  return getMinIndex(leftIdx, rightIdx);
}

long long solve(int left, int right) {
  if (left > right) return 0;

  int minIdx = query(1, 1, n, left, right);

  long long area = height[minIdx] * (right - left + 1);

  long long leftArea = solve(left, minIdx - 1);
  long long rightArea = solve(minIdx + 1, right);

  return max(area, max(leftArea, rightArea));
}

int main() {
  cin >> n;

  height.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> height[i + 1];
  }

  tree.assign(4 * n + 1, 0);
  build(1, 1, n);

  cout << solve(1, n) << "\n";
  return 0;
}