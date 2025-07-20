#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> odd_numbers;
vector<int> even_numbers;

void build(int node, int start, int end) {
  if (start == end) {
    if (arr[start] % 2 == 1) {
      // 홀수
      odd_numbers[node] = 1;
      even_numbers[node] = 0;
    } else {
      // 짝수
      odd_numbers[node] = 0;
      even_numbers[node] = 1;
    }
  } else {
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    odd_numbers[node] = odd_numbers[2 * node] + odd_numbers[2 * node + 1];
    even_numbers[node] = even_numbers[2 * node] + even_numbers[2 * node + 1];
  }
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    arr[idx] = val;

    if (arr[idx] % 2 == 1) {
      odd_numbers[node] = 1;
      even_numbers[node] = 0;
    } else {
      odd_numbers[node] = 0;
      even_numbers[node] = 1;
    }
  } else {
    int mid = (start + end) / 2;

    if (idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }

    odd_numbers[node] = odd_numbers[2 * node] + odd_numbers[2 * node + 1];
    even_numbers[node] = even_numbers[2 * node] + even_numbers[2 * node + 1];
  }
}

int query(int node, int start, int end, int left, int right,
          vector<int>& tree) {
  if (right < start || left > end) return 0;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  int left_query = query(2 * node, start, mid, left, right, tree);
  int right_query = query(2 * node + 1, mid + 1, end, left, right, tree);

  return left_query + right_query;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  arr.resize(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  odd_numbers.resize(4 * N + 1, 0);
  even_numbers.resize(4 * N + 1, 0);

  build(1, 1, N);

  cin >> M;

  for (int i = 0; i < M; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      int idx, val;
      cin >> idx >> val;

      update(1, 1, N, idx, val);
    } else if (comm == 2) {
      int left, right;
      cin >> left >> right;

      cout << query(1, 1, N, left, right, even_numbers) << "\n";
    } else {
      int left, right;
      cin >> left >> right;

      cout << query(1, 1, N, left, right, odd_numbers) << "\n";
    }
  }

  return 0;
}