#include <stdio.h>
#include <stdlib.h>

int cntMinus = 0, cntZero = 0, cntPlus = 0;

int isSame(int r, int c, int size, const int** paper) {
  int first = paper[r][c];

  for (int i = r; i < r + size; i++) {
    for (int j = c; j < c + size; j++) {
      if (paper[i][j] != first) return 0;
    }
  }

  return 1;
}

void solve(int r, int c, int size, const int** paper) {
  if (isSame(r, c, size, paper)) {
    int val = paper[r][c];

    if (val == 1)
      cntPlus++;
    else if (val == 0)
      cntZero++;
    else
      cntMinus++;

    return;
  }

  int newSize = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(r + i * newSize, c + j * newSize, newSize, paper);
    }
  }

  return;
}

int main() {
  int N;
  scanf("%d", &N);

  int** paper = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    paper[i] = (int*)malloc(N * sizeof(int));

    for (int j = 0; j < N; j++) {
      scanf("%d", &paper[i][j]);
    }
  }

  solve(0, 0, N, paper);

  printf("%d\n%d\n%d", cntMinus, cntZero, cntPlus);

  // 메모리 해제
  for (int i = 0; i < N; i++) {
    free(paper[i]);
  }
  free(paper);

  return 0;
}