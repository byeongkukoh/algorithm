#include <stdio.h>

int main() {
  int a1, a2, a3;
  scanf("%d %d %d", &a1, &a2, &a3);

  if (a1 == 60 && a2 == 60 && a3 == 60) {
    printf("Equilateral");
  } else if (a1 + a2 + a3 == 180 && (a1 == a2 || a2 == a3 || a1 == a3)) {
    printf("Isosceles");
  } else if (a1 + a2 + a3 == 180 && a1 != a2 && a2 != a3 && a1 != a3) {
    printf("Scalene");
  } else {
    printf("Error");
  }

  return 0;
}