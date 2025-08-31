#include <stdio.h>

int main() {
  int rot = 0;

  for (int i = 0; i < 10; i++) {
    int comm;
    scanf("%d", &comm);

    if (comm == 1) {
      rot = (rot + 90) % 360;
    } else if (comm == 2) {
      rot = (rot + 180) % 360;
    } else {
      if (rot == 0) {
        rot = 270;
      } else {
        rot = (rot - 90) % 360;
      }
    }
  }

  if (rot == 0)
    printf("N");
  else if (rot == 90)
    printf("E");
  else if (rot == 180)
    printf("S");
  else
    printf("W");

  return 0;
}