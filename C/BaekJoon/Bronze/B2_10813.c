#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int arr[101] = {0};

  for (int i = 0; i <= n; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    scanf("%d %d", &from, &to);

    int temp = arr[from];
    arr[from] = arr[to];
    arr[to] = temp;
  }

  for (int i = 1; i <= n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}