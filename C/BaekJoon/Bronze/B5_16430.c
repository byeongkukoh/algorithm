#include <stdio.h>

int gcd(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int main() {
  int A, B;
  scanf("%d %d", &A, &B);

  int P = B - A;
  int Q = B;

  int g = gcd(P, Q);

  if (g != 1) {
    P = P / g;
    Q = Q / g;
  }

  printf("%d %d", P, Q);

  return 0;
}