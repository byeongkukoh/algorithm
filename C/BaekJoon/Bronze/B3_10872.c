#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  long long res = 1;

  for (int i = 1; i <= n; i++) {
    res *= i;
  }

  printf("%lld", res);

  return 0;
}