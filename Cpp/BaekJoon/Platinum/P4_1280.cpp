#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define MAX_N 200000

using namespace std;

int N = 0;
long long tree_cnt[MAX_N * 4 + 1];
long long tree_sum[MAX_N * 4 + 1];

// 누적 합 업데이트
void update(int node, int start, int end, int idx, long long val) {
  if (start == end) {
    tree_cnt[node] += 1;
    tree_sum[node] += val;
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    tree_cnt[node] = tree_cnt[2 * node] + tree_cnt[2 * node + 1];
  }
}

// 누적 합 쿼리
long long sum_query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree_sum[node];

  int mid = (start + end) / 2;

  long long left_sum = sum_query(2 * node, start, mid, left, right);
  long long right_sum = sum_query(2 * node + 1, mid + 1, end, left, right);

  return left_sum + right_sum;
}

// 누적 개수 쿼리
long long cnt_query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree_cnt[node];

  int mid = (start + end) / 2;

  long long left_sum = cnt_query(2 * node, start, mid, left, right);
  long long right_sum = cnt_query(2 * node + 1, mid + 1, end, left, right);

  return left_sum + right_sum;
}

int main() {
  cin >> N;

  vector<long long> arr;
  arr.resize(N + 1, 0);

  for (int i = 0; i < N; i++) {
    long long temp;
    cin >> temp;

    update(1, 0, MAX_N, temp, temp);

    if (i == 0) {
      arr[i + 1] = 0;
      continue;
    }

    int left_cnt = cnt_query(1, 0, MAX_N, 0, temp - 1);
    long long left_sum = sum_query(1, 0, MAX_N, 0, temp - 1);

    int right_cnt = cnt_query(1, 0, MAX_N, temp + 1, MAX_N);
    long long right_sum = sum_query(1, 0, MAX_N, temp + 1, MAX_N);

    long long dist =
        (temp * left_cnt - left_sum) + (right_sum - temp * right_cnt);

    arr[i + 1] = dist;
  }

  long long ans = 1;
  for (int i = 2; i < N + 1; i++) {
    ans = (ans % 1000000007) * (arr[i] % 1000000007) % 1000000007;
  }

  cout << ans;

  return 0;
}