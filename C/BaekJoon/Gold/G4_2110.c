#include <stdio.h>
#include <stdlib.h>

int n, c;
int house[200001] = {0};

int cmp(const void* a, const void* b) {
  int x = *(int*)a;
  int y = *(int*)b;

  return x - y;
}

int check(int dist) {
  int cnt = 1;
  int last = house[0];

  for (int i = 1; i < n; i++) {
    if (house[i] - last >= dist) {
      cnt++;
      last = house[i];
    }
  }

  if (cnt >= c) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  scanf("%d %d", &n, &c);

  for (int i = 0; i < n; i++) {
    scanf("%d", &house[i]);
  }

  qsort(house, n, sizeof(int), cmp);

  int lo = 1;
  int hi = house[n - 1] - house[0];

  int dist = 0;

  while (hi >= lo) {
    int mid = (hi + lo) / 2;

    if (check(mid)) {
      lo = mid + 1;
      dist = mid;
    } else {
      hi = mid - 1;
    }
  }

  printf("%d", dist);

  return 0;
}