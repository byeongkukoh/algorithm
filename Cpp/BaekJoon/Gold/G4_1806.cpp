#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, s;
  cin >> n >> s;

  vector<long long> arr;
  arr.resize(n + 1, 0);

  for (int i = 1; i < n + 1; i++) {
    int temp;
    cin >> temp;

    arr[i] = arr[i - 1] + temp;
  }

  int minLen = INT_MAX;

  int lo = 0;

  for (int hi = 0; hi < n + 1; hi++) {
    long long res = arr[hi] - arr[lo];

    while (res >= s) {
      if (minLen > hi - lo) minLen = hi - lo;

      lo += 1;
      res = arr[hi] - arr[lo];
    }
  }

  if (minLen == INT_MAX)
    cout << 0;
  else
    cout << minLen;

  return 0;
}