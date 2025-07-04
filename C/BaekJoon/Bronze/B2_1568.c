#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int count = 0;
  int now = 1;
  while (n != 0) {
    count++;
    if (n < now) now = 1;
    n -= now;
    now++;
  }

  printf("%d", count);

  return 0;
}