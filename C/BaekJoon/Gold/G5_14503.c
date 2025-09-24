#include <stdio.h>

int N, M;
int sY, sX, dir;
int maxCount = 0;

int MAP[50][50];
int check[50][50];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int checkDirection(int dir) {
  int temp = dir;

  if (temp == 0) {
    temp = temp + 3;
  } else {
    temp = temp - 1;
  }

  return temp;
}

void simulator() {
  while (1) {
    // 현재 칸 청소
    if (check[sY][sX] == 0) {
      maxCount++;
      check[sY][sX] = 1;
    }

    // 주변 4칸 확인
    int checkNoClean = 0;
    for (int i = 0; i < 4; i++) {
      int ny = sY + dy[i];
      int nx = sX + dx[i];

      if (MAP[ny][nx] != 1 && check[ny][nx] != 1) {
        checkNoClean = 1;
        break;
      }
    }

    // 청소되지 않은 빈칸이 엾는 경우
    if (checkNoClean == 0) {
      // 후진 여부 확인
      int tempDir = (dir + 2) % 4;
      int ny = sY + dy[tempDir];
      int nx = sX + dx[tempDir];

      // 벽인 경우 종료
      if (MAP[ny][nx] == 1) return;

      // 이동할 수 있는 경우 (후진 가능)
      sY = ny;
      sX = nx;
      continue;
    }

    if (checkNoClean == 1) {
      // 반시계 방향 90도 회전
      dir = checkDirection(dir);

      // 다음 이동 좌표 확인
      int ny = sY + dy[dir];
      int nx = sX + dx[dir];

      // 전방이 벽이면 다음 단계로 진행
      if (MAP[ny][nx] == 1) continue;

      // 청소되지 않은 칸이면
      if (check[ny][nx] == 0) {
        sY = ny;
        sX = nx;
      }
    }
  }

  return;
}

int main() {
  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &sY, &sX, &dir);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &MAP[i][j]);

      check[i][j] = 0;
    }
  }

  simulator();

  printf("%d", maxCount);

  return 0;
}