#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tower {
  int id;   // 임의의 포탑 ID
  int row;  // 위치좌표
  int col;
  int atk;            // 공격력
  int last_turn = 0;  // 최근 공격한 turn
};

int N, M, K;
int remain_tower = 0;

vector<vector<Tower>> map;    // 포탑 지도
vector<bool> isDistory;       // 파괴 여부 저장 (ID 기반)
vector<vector<int>> visited;  // 최단 거리 (방문 여부)
vector<Tower> path;           // 방문 경로 (ID 기반)
vector<bool> isAttack;        // 공격 관여 여부

void init();               // 초기화 함수
Tower findAttacker();      // 공격자 탐색
Tower findTarget();        // 공격 타겟 탐색
void laser(int y, int x);  // laser 공격 여부 BFS

int main() {
  init();

  // K번 턴 반복
  for (int k = 0; k < K; k++) {
    // 남은 타워가 1개라면, 즉시 종료
    if (remain_tower == 1) break;

    isAttack.assign(N * M, false);

    // 공격자 선택
    Tower attk = findAttacker();
    attk.atk += (N + M);
    attk.last_turn = k + 1;
    isAttack[attk.id] = true;

    // 타겟 선택
    Tower target = findTarget();
    isAttack[target.id] = true;

    // 레이저 공격
    laser(attk.row, attk.col);

    // 레이저 공격이 가능하면,
    if (visited[target.row][target.col] != -1) {
      target.atk = target.atk - attk.atk;

      if (target.atk <= 0) {
        target.atk = 0;
        isDistory[target.id] = true;
        remain_tower--;
      }

      map[target.row][target.col] = target;

      // 경로에 있는 타겟 공격
      int path_id = target.id;

      while (1) {
        Tower next = path[path_id];
        if (next.id == attk.id) break;

        next.atk = next.atk - (attk.atk / 2);
        if (next.atk <= 0) {
          next.atk = 0;
          isDistory[next.id] = true;
          remain_tower--;
        }
        isAttack[next.id] = true;
        map[next.row][next.col] = next;

        path_id = next.id;
      }
    } else {  // 레이저 공격 불가능하면,
      target.atk = target.atk - attk.atk;

      if (target.atk <= 0) {
        target.atk = 0;
        isDistory[target.id] = true;
        remain_tower--;
      }

      map[target.row][target.col] = target;

      // 주변 공격
      int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
      int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

      for (int i = 0; i < 8; i++) {
        int ny = target.row + dy[i];
        int nx = target.col + dx[i];

        if (ny < 0)
          ny = N - 1;
        else if (ny >= N)
          ny = 0;

        if (nx < 0)
          nx = M - 1;
        else if (nx >= M)
          nx = 0;

        // 이미 파괴된 포탑이면 스킵
        if (map[ny][nx].atk == 0) continue;
        // 공격자이면 스킵
        if (ny == attk.row && nx == attk.col) continue;

        map[ny][nx].atk = map[ny][nx].atk - (attk.atk / 2);

        if (map[ny][nx].atk <= 0) {
          map[ny][nx].atk = 0;
          isDistory[map[ny][nx].id] = true;
          remain_tower--;
        }

        isAttack[map[ny][nx].id] = true;
      }
    }

    map[attk.row][attk.col] = attk;

    // 공격 종료 후 정비
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j].atk == 0) continue;
        if (isAttack[map[i][j].id]) continue;

        map[i][j].atk += 1;
      }
    }
  }

  // 최대 값 찾기
  int max_value = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (max_value < map[i][j].atk) {
        max_value = map[i][j].atk;
      }
    }
  }

  cout << max_value;

  return 0;
}

void init() {
  cin >> N >> M >> K;

  map.resize(N, vector<Tower>(M));
  isDistory.resize(N * M, true);

  int id = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Tower temp = {id, i, j, 0};
      cin >> temp.atk;

      if (temp.atk != 0) {
        isDistory[temp.id] = false;
        remain_tower++;
      }

      map[i][j] = temp;
      id++;
    }
  }

  return;
}

Tower findAttacker() {
  Tower choice = {0, 0, 0, INT_MAX, 0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Tower now = map[i][j];

      if (now.atk == 0) continue;

      if (choice.atk >= now.atk) {
        if (choice.atk > now.atk)
          choice = now;
        else {
          if (choice.last_turn < now.last_turn)
            choice = now;
          else if (choice.last_turn == now.last_turn) {
            if (choice.row + choice.col < now.row + now.col)
              choice = now;
            else if (choice.row + choice.col == now.row + now.col) {
              if (choice.col < now.col) choice = now;
            }
          }
        }
      }
    }
  }

  return choice;
}

Tower findTarget() {
  Tower choice = {0, 0, 0, 0, 0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Tower now = map[i][j];

      if (now.atk == 0) continue;

      if (choice.atk <= now.atk) {
        if (choice.atk < now.atk)
          choice = now;
        else {
          if (choice.last_turn > now.last_turn)
            choice = now;
          else if (choice.last_turn == now.last_turn) {
            if (choice.row + choice.col > now.row + now.col)
              choice = now;
            else if (choice.row + choice.col == now.row + now.col) {
              if (choice.col > now.col) choice = now;
            }
          }
        }
      }
    }
  }

  return choice;
}

void laser(int y, int x) {
  struct Node {
    int y, x;
  };

  int dy[] = {0, 1, 0, -1};
  int dx[] = {1, 0, -1, 0};

  visited.assign(N, vector<int>(M, -1));
  path.assign(N * M, {-1, -1, -1, -1, -1});

  queue<Node> que;
  que.push({y, x});

  visited[y][x] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      // 경계를 벗어나는 경우 처리
      if (ny < 0) {
        ny = N - 1;
      } else if (ny >= N) {
        ny = 0;
      }

      if (nx < 0) {
        nx = M - 1;
      } else if (nx >= M) {
        nx = 0;
      }

      // 파괴된 포탑이면 진입 불가
      if (map[ny][nx].atk == 0) continue;
      // 방문을 했는데, 더 빠른 경로였다면 스킵
      if (visited[ny][nx] != -1 && visited[ny][nx] <= visited[now.y][now.x] + 1)
        continue;

      que.push({ny, nx});
      visited[ny][nx] = visited[now.y][now.x] + 1;
      path[map[ny][nx].id] = map[now.y][now.x];
    }
  }
}