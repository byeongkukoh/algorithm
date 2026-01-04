#include <stdio.h>
#include <stdlib.h>

void solve(int r, int c, int size, char** stars) {
  if (size == 1) {
    stars[r][c] = '*';

    return;
  }

  int newSize = size / 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;

      solve(r + i * newSize, c + j * newSize, newSize, stars);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);

  char** stars = (char**)malloc(N * sizeof(char*));
  for (int i = 0; i < N; i++) {
    stars[i] = (char*)malloc(N * sizeof(char));

    for (int j = 0; j < N; j++) {
      stars[i][j] = ' ';
    }
  }

  solve(0, 0, N, stars);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c", stars[i][j]);
    }
    printf("\n");
  }

  // 메모리 해제
  for (int i = 0; i < N; i++) {
    free(stars[i]);
  }
  free(stars);

  return 0;
}