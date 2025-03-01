#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long> lenLine;

  int k, n;
  cin >> k >> n;

  long max_len = 0;
  for (int i = 0; i < k; i++) {
    long temp;
    cin >> temp;

    if (temp > max_len) {
      max_len = temp;
    }

    lenLine.push_back(temp);
  }

  long low = 1;
  long high = max_len;
  long ans = 0;

  while (low <= high) {
    int cnt = 0;
    long mid = (low + high) / 2;

    for (int i = 0; i < k; i++) {
      cnt += lenLine[i] / mid;
    }

    if (cnt >= n) {
      low = mid + 1;

      if (ans < mid) {
        ans = mid;
      }
    } else {
      high = mid - 1;
    }
  }

  cout << ans;

  return 0;
}