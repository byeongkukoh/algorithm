#include <stdio.h>

int main() {
  int cost;
  scanf("%d", &cost);

  int n;
  scanf("%d", &n);

  int total = 0;
  for (int i = 0; i < n; i++) {
    int temp, cnt;
    scanf("%d %d", &temp, &cnt);

    total += temp * cnt;
  }

  if (cost == total)
    printf("Yes");
  else
    printf("No");

  return 0;
}