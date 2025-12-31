#include <stdio.h>
#include <stdlib.h>

int main() {
  int test;
  scanf("%d", &test);

  for (int t = 0; t < test; t++) {
    int n;
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }

    int max_price = 0;
    long long result = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (max_price < arr[i]) {
        max_price = arr[i];
      } else {
        result += (max_price - arr[i]);
      }
    }

    printf("%lld\n", result);

    free(arr);
  }

  return 0;
}