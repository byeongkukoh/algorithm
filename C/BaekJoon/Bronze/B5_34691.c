#include <stdio.h>
#include <string.h>

int main() {
  while (1) {
    char str[10];
    scanf("%s", str);

    if (strcmp(str, "end") == 0) break;

    if (strcmp(str, "animal") == 0) {
      printf("Panthera tigris \n");
    } else if (strcmp(str, "tree") == 0) {
      printf("Pinus densiflora \n");
    } else if (strcmp(str, "flower") == 0) {
      printf("Forsythia koreana \n");
    } else {
      break;
    }
  }

  return 0;
}