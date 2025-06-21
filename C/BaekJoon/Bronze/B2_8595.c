#include <ctype.h>
#include <stdio.h>
#include <string.h>

char str[5000001];

int main() {
  int n;
  scanf("%d", &n);

  scanf("%s", str);

  int temp = 0;
  int flag = 0;
  long long result = 0;

  for (int i = 0; i < n + 1; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      temp = temp * 10 + (str[i] - '0');
      flag = 1;
    } else {
      if (flag) {
        result += temp;
        flag = 0;
        temp = 0;
      }
    }
  }

  if (flag) {
    result += temp;
  }

  printf("%lld", result);

  return 0;
}