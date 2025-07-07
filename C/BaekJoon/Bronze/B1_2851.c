#include <math.h>
#include <stdio.h>

int main() {
  int arr[10];
  int sumList[10] = {0};

  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }

  sumList[0] = arr[0];

  int ans = sumList[0];
  for (int i = 1; i < 10; i++) {
    sumList[i] = sumList[i - 1] + arr[i];

    if (abs(100 - sumList[i]) <= abs(100 - ans)) {
      ans = sumList[i];
    }
  }

  printf("%d", ans);

  return 0;
}