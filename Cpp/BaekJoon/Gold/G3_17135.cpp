#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
  int y;
  int x;
};

struct Node {
  int y;
  int x;
  int dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    if (x != right.x) return x > right.x;

    return false;
  }
};

int N, M, D;
int maxCount = 0;

vector<bool> checkLocation;
vector<vector<int>> MAP;

int calculateDist(int enemy_y, int enemy_x, int archer_y, int archer_x) {
  return abs(enemy_y - archer_y) + abs(enemy_x - archer_x);
}

int simulator() {
  int checkCount = 0;
  int remainEnemyCount = 0;

  // 사용할 시뮬레이터 MAP 정보 초기화
  vector<vector<int>> tempMap;
  tempMap.assign(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tempMap[i][j] = MAP[i][j];

      if (tempMap[i][j] == 1) remainEnemyCount++;
    }
  }

  // 궁수 위치
  vector<Pos> archers;
  for (int i = 0; i < M; i++) {
    if (checkLocation[i]) archers.push_back({N, i});
  }

  // 시뮬레이션
  while (remainEnemyCount != 0) {
    queue<Pos> killEnemy;

    // 죽일 수 있는 적 체크
    for (int i = 0; i < 3; i++) {
      priority_queue<Node> pque;

      for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
          if (tempMap[row][col] == 1) {
            int dist = calculateDist(row, col, archers[i].y, archers[i].x);

            if (dist <= D) {
              pque.push({row, col, dist});
            }
          }
        }
      }

      if (!pque.empty()) {
        killEnemy.push({pque.top().y, pque.top().x});
      }
    }

    // 죽은 적 체크
    while (!killEnemy.empty()) {
      Pos now = killEnemy.front();
      killEnemy.pop();

      if (tempMap[now.y][now.x] == 1) {
        tempMap[now.y][now.x] = 0;

        checkCount++;
        remainEnemyCount--;
      }
    }

    // 살아 남은 적 이동
    for (int row = N - 1; row >= 0; row--) {
      for (int col = 0; col < M; col++) {
        // 맵 끝에 도달한 적 체크
        if (row == N - 1 && tempMap[row][col] == 1) {
          tempMap[row][col] = 0;
          remainEnemyCount--;

          continue;
        }

        // 맵 끝에 도달하지 않은 경우
        if (tempMap[row][col] == 1) {
          tempMap[row][col] = 0;
          tempMap[row + 1][col] = 1;
        }
      }
    }
  }

  return checkCount;
}

void locateArcher(int now, int start) {
  if (now == 3) {
    int check = simulator();

    if (maxCount < check) maxCount = check;

    return;
  }

  for (int i = start; i < M; i++) {
    if (checkLocation[i]) continue;

    checkLocation[i] = true;

    locateArcher(now + 1, i + 1);

    checkLocation[i] = false;
  }
}

int main() {
  cin >> N >> M >> D;

  MAP.assign(N, vector<int>(M, 0));
  checkLocation.assign(M, false);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> MAP[i][j];
    }
  }

  locateArcher(0, 0);

  cout << maxCount;

  return 0;
}