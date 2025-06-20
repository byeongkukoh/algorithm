#include <stdio.h>

int main() {
  int year, number;
  scanf("%d %d", &year, &number);

  printf("SN ");
  printf("%d", year);

  if (number < 27) {
    printf("%c", number + 64);
  } else {
    int q = (number - 1) / 26;
    int r = (number - 1) % 26;

    printf("%c", 'a' + q - 1);
    printf("%c", 'a' + r);
  }

  return 0;
}