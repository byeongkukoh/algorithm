#include <limits.h>
#include <stdio.h>

int main() {
  int n, m, b;
  scanf("%d %d %d", &n, &m, &b);

  int ground[250000];
  int min_value = 256;
  int max_value = 0;

  for (int i = 0; i < n * m; i++) {
    scanf("%d", &ground[i]);

    if (ground[i] > max_value) max_value = ground[i];

    if (ground[i] < min_value) min_value = ground[i];
  }

  int ansTime = INT_MAX;
  int height = 0;

  for (int target = min_value; target <= max_value; target++) {
    int dig = 0;
    int ins = 0;
    int tempTime = 0;

    for (int i = 0; i < n * m; i++) {
      if (ground[i] > target) {
        dig += (ground[i] - target);
        tempTime += (ground[i] - target) * 2;
      } else {
        ins += (target - ground[i]);
        tempTime += (target - ground[i]) * 1;
      }
    }

    if ((dig + b - ins >= 0) && (ansTime >= tempTime)) {
      ansTime = tempTime;
      height = target;
    }
  }

  printf("%d %d", ansTime, height);

  return 0;
}