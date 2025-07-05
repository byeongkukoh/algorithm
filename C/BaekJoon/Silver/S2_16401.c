#include <stdio.h>
#include <stdlib.h>

int m, n;
int snack[1000000];

int cmp(const void* a, const void* b) {
  int x = *(int*)a;
  int y = *(int*)b;

  return x - y;
}

int check(int leng) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (snack[i] >= leng) {
      cnt += snack[i] / leng;
    }
  }

  if (cnt >= m) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  scanf("%d %d", &m, &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &snack[i]);
  }

  qsort(snack, n, sizeof(int), cmp);

  int lo = 1;
  int hi = snack[n - 1];

  int leng = 0;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(mid)) {
      lo = mid + 1;
      leng = mid;
    } else {
      hi = mid - 1;
    }
  }

  printf("%d", leng);

  return 0;
}