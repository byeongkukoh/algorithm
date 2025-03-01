#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<long long> tree;
  long long max_high = 0;

  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;

    if (temp > max_high) max_high = temp;

    tree.push_back(temp);
  }

  long long low = 1;
  long long high = max_high;
  long long ans = 0;

  while (low <= high) {
    long long total = 0;
    long long mid = (low + high) / 2;

    for (int i = 0; i < n; i++) {
      long long temp;
      if (tree[i] < mid)
        temp = 0;
      else
        temp = tree[i] - mid;

      total += temp;
    }

    if (total >= m) {
      low = mid + 1;

      if (mid > ans) {
        ans = mid;
      }
    } else {
      high = mid - 1;
    }
  }

  cout << ans;

  return 0;
}