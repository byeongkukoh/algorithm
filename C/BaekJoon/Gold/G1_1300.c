#include <stdio.h>

long long N, k;

long long min_check(long long a, long long b) {
  if (a > b) return b;

  return a;
}

int check(long long mid) {
  long long cnt = 0;

  for (int i = 1; i <= N; i++) {
    cnt += min_check(N, mid / i);
  }

  if (cnt >= k) return 1;

  return 0;
}

int main() {
  scanf("%lld %lld", &N, &k);

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

  printf("%lld", ans);

  return 0;
}