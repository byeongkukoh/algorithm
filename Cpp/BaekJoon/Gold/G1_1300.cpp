#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long N, k;

bool check(long long mid) {
  long long cnt = 0;

  for (int i = 1; i <= N; i++) {
    cnt += min(N, mid / i);
  }

  if (cnt >= k) return true;

  return false;
}

int main() {
  cin >> N >> k;

  long long lo = 1;
  long long hi = N * N;

  long long ans = 0;

  while (lo <= hi) {
    long long mid = (lo + hi) / 2;

    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans;

  return 0;
}