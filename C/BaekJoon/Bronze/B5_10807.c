#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[230] = {0};

  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);

    arr[temp + 100] += 1;
  }

  int res;
  scanf("%d", &res);

  printf("%d", arr[res + 100]);

  return 0;
}