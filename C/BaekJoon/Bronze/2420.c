#include <stdio.h>

int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);

  long long res = n - m;

  if (res < 0) {
    printf("%lld", -res);
  } else {
    printf("%lld", res);
  }

  return 0;
}