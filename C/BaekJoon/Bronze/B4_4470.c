#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    getchar();

    char ch[60];
    scanf("%[^\n]", ch);

    printf("%d. %s\n", i + 1, ch);
  }

  return 0;
}