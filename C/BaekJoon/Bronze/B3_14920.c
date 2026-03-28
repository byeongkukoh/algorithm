#include <stdio.h>

int main() {
  int C;
  scanf("%d", &C);

  int n = 1;

  while (C != 1) {
    n++;

    if (C % 2 == 0)
      C = C / 2;
    else
      C = C * 3 + 1;
  }

  printf("%d", n);

  return 0;
}