#include <stdio.h>

int main() {
  int N, W, H, L;
  scanf("%d %d %d %d", &N, &W, &H, &L);

  int width = W / L;
  int height = H / L;

  int pos = width * height;

  if (pos < N)
    printf("%d", pos);

  else
    printf("%d", N);

  return 0;
}