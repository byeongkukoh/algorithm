#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int* L = malloc(sizeof(int) * (n + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &L[i]);
  }

  int* J = malloc(sizeof(int) * (n + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &J[i]);
  }

  int dp[100] = {0};

  for (int i = 1; i <= n; i++) {
    if (L[i] >= 100) continue;

    for (int used_hp = 99; used_hp >= L[i]; used_hp--) {
      if (dp[used_hp] > dp[used_hp - L[i]] + J[i]) continue;

      dp[used_hp] = dp[used_hp - L[i]] + J[i];
    }
  }

  int result = 0;
  for (int i = 0; i < 100; i++) {
    if (result > dp[i]) continue;

    result = dp[i];
  }

  printf("%d", result);

  return 0;
}