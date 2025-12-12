#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  if (a <= b) {
    printf("high speed rail");
  } else {
    printf("flight");
  }

  return 0;
}