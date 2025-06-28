#include <stdio.h>

int main() {
  int hour, min;
  scanf("%d %d", &hour, &min);

  int time;
  scanf("%d", &time);

  min = min + time;

  hour = (hour + (min / 60)) % 24;
  min = min % 60;

  printf("%d %d", hour, min);

  return 0;
}