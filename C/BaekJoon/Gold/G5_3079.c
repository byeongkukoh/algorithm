#include <stdio.h>
#include <stdlib.h>

int N, M;
long long timeList[100000];

int cmp(const void* a, const void* b) {
  long long x = *(long long*)a;
  long long y = *(long long*)b;

  if (x > y) return 1;
  if (x < y) return -1;

  return 0;
}

int check(long long timeVal) {
  long long person = 0;

  for (int i = 0; i < N; i++) {
    person += timeVal / timeList[i];

    if (person >= M) return 1;
  }

  return 0;
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%lld", &timeList[i]);
  }

  qsort(timeList, N, sizeof(long long), cmp);

  long long lo = 1;
  long long hi = timeList[N - 1] * M;

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