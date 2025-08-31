#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  int jinju_idx = 0;
  int res_cnt = 0;

  int cost[1001] = {0};
  for (int i = 1; i <= n; i++) {
    char name[16];
    scanf("%s %d", &name, &cost[i]);

    if (strcmp("jinju", name) == 0) jinju_idx = i;
  }

  for (int i = 1; i <= n; i++) {
    if (cost[i] > cost[jinju_idx]) res_cnt++;
  }

  printf("%d\n", cost[jinju_idx]);
  printf("%d", res_cnt);

  return 0;
}