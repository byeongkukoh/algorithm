#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
  int size;
  int cnt;
};

struct QUE {
  int row;
  int col;
  int dist;

  bool operator<(QUE right) const {
    if (dist != right.dist) return dist > right.dist;
    if (row != right.row) return row > right.row;

    return col > right.col;
  }
};

int N;
int fishCount = 0;
int timeCounter = 0;

Node baby;
vector<vector<int>> MAP;
vector<vector<int>> dist;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
  queue<QUE> que;
  que.push({y, x, 0});
  dist[y][x] = 0;

  while (!que.empty()) {
    QUE now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];
      int nextDist = now.dist + 1;

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (MAP[ny][nx] > baby.size) continue;
      if (dist[ny][nx] <= nextDist) continue;

      que.push({ny, nx, nextDist});
      dist[ny][nx] = nextDist;
    }
  }
}

void simulator() {
  while (fishCount != 0) {
    // 거리 저장 벡터 초기화
    dist.assign(N, vector<int>(N, INT_MAX));

    // 갈 수 있는 위치 거리 탐색
    bfs(baby.row, baby.col);

    priority_queue<QUE> pque;  // 이동 가능한 거리로 정렬
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][j] == INT_MAX) continue;   // 이동 못하면 패스
        if (MAP[i][j] == baby.size) continue;  // 크기가 같으면 패스
        if (MAP[i][j] == 0) continue;          // 물고기가 없으면 패스

        pque.push({i, j, dist[i][j]});  // 이동할 수 있으면 모두 추가
      }
    }

    // 이동 가능한 위치가 없으면 시뮬레이션 종료
    if (pque.empty()) {
      return;
    }

    // 가장 가까운 물고기로 이동 및 먹음 처리
    QUE curr = pque.top();
    pque.pop();

    timeCounter += curr.dist;  // 걸린 시간 갱신
    baby.row = curr.row;       // 위치 갱신
    baby.col = curr.col;
    baby.cnt += 1;  // 먹은 물고기 수 갱신

    MAP[curr.row][curr.col] = 0;  // 없어진 물고기 처리
    fishCount--;                  // 남은 물고기 수 갱신

    // 아기상어 사이즈 확인
    if (baby.cnt == baby.size) {
      baby.size++;
      baby.cnt = 0;
    }
  }

  return;
}

int main() {
  cin >> N;

  MAP.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> MAP[i][j];

      if (MAP[i][j] == 9) {
        baby = {i, j, 2, 0};
        MAP[i][j] = 0;
      }

      if (MAP[i][j] != 0) {
        fishCount++;
      }
    }
  }

  // 물고기가 없으면 종료
  if (fishCount == 0) {
    cout << 0;
    return 0;
  }

  simulator();

  cout << timeCounter;

  return 0;
}