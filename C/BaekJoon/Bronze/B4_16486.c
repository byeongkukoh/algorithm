#include <stdio.h>

#define pi 3.141592

int main() {
  double d1, d2;

  scanf("%lf %lf", &d1, &d2);

  double line = d1 * 2.0 + (2.0 * pi * d2);

  printf("%lf", line);

  return 0;
}