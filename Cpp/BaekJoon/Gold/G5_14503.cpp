#include <iostream>
#include <vector>

using namespace std;

int N, M;
int sY, sX, dir;
int maxCount = 0;

vector<vector<int>> MAP;
vector<vector<bool>> check;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 반시계 방향 90도 회전
int checkDirection(int dir) {
  int temp = dir;

  if (dir > 0) {
    temp = temp - 1;
  } else {
    temp = temp + 3;
  }

  return temp;
}

void simulator() {
  while (true) {
    // 현재 칸이 청소되지 않았으면, 청소
    if (!check[sY][sX]) {
      maxCount++;
      check[sY][sX] = true;
    }

    // 주변 4칸 확인
    bool checkNoClean = false;
    for (int i = 0; i < 4; i++) {
      int ny = sY + dy[i];
      int nx = sX + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if (MAP[ny][nx] != 1 && !check[ny][nx]) {
        checkNoClean = true;
        break;
      }
    }

    // 청소되지 않은 빈칸이 없는 경우
    if (!checkNoClean) {
      // 후진할 수 있는지 확인
      int tempDir = (dir + 2) % 4;
      int ny = sY + dy[tempDir];
      int nx = sX + dx[tempDir];

      // 경계선을 넘어가는 경우 (벽으로 간주)
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) return;

      // 벽인 경우
      if (MAP[ny][nx] == 1) return;

      // 이동할 수 있는 경우
      sY = ny;
      sX = nx;
      continue;
    }

    // 청소되지 않은 빈칸이 있는 경우
    if (checkNoClean) {
      dir = checkDirection(dir);

      int ny = sY + dy[dir];
      int nx = sX + dx[dir];

      // 전방이 벽이면 다음 단계로 진행
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (MAP[ny][nx] == 1) continue;

      // 전방이 청소하지 않은 칸이면 전진
      if (!check[ny][nx]) {
        sY = ny;
        sX = nx;
      }
    }
  }

  return;
}

int main() {
  cin >> N >> M;
  cin >> sY >> sX >> dir;

  MAP.assign(N, vector<int>(M, 0));
  check.assign(N, vector<bool>(M, false));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> MAP[i][j];
    }
  }

  simulator();

  cout << maxCount;

  return 0;
}