#include <limits.h>
#include <stdio.h>

int main() {
  int n, s;
  scanf("%d %d", &n, &s);

  long long arr[100001];
  arr[0] = 0;

  for (int i = 1; i < n + 1; i++) {
    int temp;
    scanf("%d", &temp);

    arr[i] = arr[i - 1] + temp;
  }

  int lo = 0;
  int minLength = INT_MAX;

  for (int hi = 1; hi < n + 1; hi++) {
    int res = arr[hi] - arr[lo];

    while (res >= s) {
      if (minLength > hi - lo) {
        minLength = hi - lo;
      }

      lo++;

      res = arr[hi] - arr[lo];
    }
  }

  if (minLength == INT_MAX) {
    printf("%d", 0);
  } else {
    printf("%d", minLength);
  }

  return 0;
}