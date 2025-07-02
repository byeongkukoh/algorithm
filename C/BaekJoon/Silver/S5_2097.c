#include <math.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  if (n == 1 || n == 2) {
    printf("%d", 4);
    return 0;
  }

  int root = round(sqrt(n));

  if (root * root >= n) {
    printf("%d", (root - 1) * 4);
  } else {
    printf("%d", (root - 1) * 2 + root * 2);
  }

  return 0;
}