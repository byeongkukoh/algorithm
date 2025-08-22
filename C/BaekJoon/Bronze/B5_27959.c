#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  if (100 * n < m)
    printf("No");
  else
    printf("Yes");

  return 0;
}