#include <stdio.h>

int findMax(int a, int b) {
  if (a > b) return a;

  if (b > a) return b;

  return a;
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if (a == b && b == c) {
    printf("%d\n", 10000 + a * 1000);
  } else if (a == b || b == c || c == a) {
    if (a == b) {
      printf("%d\n", 1000 + a * 100);
    } else if (b == c) {
      printf("%d\n", 1000 + b * 100);
    } else {
      printf("%d\n", 1000 + c * 100);
    }
  } else {
    int maxValue = findMax(a, findMax(b, c));

    printf("%d\n", maxValue * 100);
  }

  return 0;
}