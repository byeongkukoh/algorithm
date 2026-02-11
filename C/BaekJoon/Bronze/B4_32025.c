#include <stdio.h>

int main() {
  int H, W;
  scanf("%d", &H);
  scanf("%d", &W);

  if (H > W) {
    printf("%d", W * 50);
  } else {
    printf("%d", H * 50);
  }

  return 0;
}