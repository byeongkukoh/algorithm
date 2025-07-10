#include <stdio.h>

int main() {
  char str[51];
  scanf("%s", str);

  int check_minus = 0;
  long long temp = 0;

  long long sum1 = 0;
  long long sum2 = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    char ch = str[i];

    if (ch >= '0' && ch <= '9') {
      temp = temp * 10 + (int)(ch - '0');
      continue;
    }

    if (check_minus == 0 && ch == '+') {
      sum1 += temp;
      temp = 0;
      continue;
    }

    if (check_minus == 0 && ch == '-') {
      check_minus = 1;
      sum1 += temp;
      temp = 0;
      continue;
    }

    if (check_minus == 1 && (ch == '+' || ch == '-')) {
      sum2 += temp;
      temp = 0;
      continue;
    }
  }

  if (check_minus == 1) {
    printf("%lld", sum1 - sum2 - temp);
  } else {
    printf("%lld", sum1 + temp);
  }

  return 0;
}