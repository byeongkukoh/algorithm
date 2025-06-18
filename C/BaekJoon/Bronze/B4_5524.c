#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char name[30];
    scanf("%s", name);

    for (int j = 0; name[j] != '\0'; j++) {
      if (name[j] >= 'A' && name[j] <= 'Z') {
        printf("%c", name[j] + 32);
      } else {
        printf("%c", name[j]);
      }
    }

    printf("\n");
  }

  return 0;
}