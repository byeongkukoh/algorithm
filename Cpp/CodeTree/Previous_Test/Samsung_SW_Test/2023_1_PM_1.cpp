#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Person {
  int id;         // 참가자 고유 번호
  int row;        // 현재 위치 좌표 (행)
  int col;        // 현재 위치 좌표 (열)
  int mvCnt = 0;  // 이동 횟수
  int dist = 0;   // 출구까지의 거리
};

struct Node {
  int row;
  int col;
};

int N, M, K;              // 초기 정보
int cntNoExitPeople = 0;  // 탈출 못한 참가자 수
Node locExit;             // 탈출구 위치

vector<vector<int>> map;         // 맵 정보
vector<vector<int>> people_map;  // 참여자 위치 정보
vector<Person> people;           // 참여자 정보
vector<bool> exitPeople;         // 참여자 탈출 여부
vector<bool> rotatePeople;       // 참여자 회전 여부

void init();                    // 초기화
int calDist(int row, int col);  // 탈출구까지 거리 계산
void move(int id);              // 참여자 이동
void rotate_map();              // 맵 회전

int main() {
  // 초기화
  init();

  // 초기 거리 계산
  for (int id = 1; id <= M; id++) {
    int dist = calDist(people[id].row, people[id].col);

    people[id].dist = dist;
  }

  // K초 동안 이동
  for (int k = 1; k <= K; k++) {
    // 탈출 못한 사람이 없으면 종료
    if (cntNoExitPeople == 0) break;

    // 참가자 이동
    for (int id = 1; id <= M; id++) {
      // 참가자가 탈출했으면 패스
      if (exitPeople[id]) continue;

      move(id);
    }

    // 이동이 끝나면 참가자 위치 맵 갱신
    people_map.assign(N + 2, vector<int>(N + 2, 0));
    for (int id = 1; id <= M; id++) {
      if (exitPeople[id]) continue;

      int row = people[id].row;
      int col = people[id].col;
      people_map[row][col] = id;
    }

    // 이동이 끝나고 나면 미로 회전
    rotate_map();

    // 출구까지 거리 갱신
    for (int id = 1; id <= M; id++) {
      people[id].dist = calDist(people[id].row, people[id].col);
    }
  }

  // 총 이동 횟수 계산
  int total_cnt_move = 0;
  for (int id = 1; id <= M; id++) {
    total_cnt_move += people[id].mvCnt;
  }

  // 출력
  cout << total_cnt_move << "\n";
  cout << locExit.row << " " << locExit.col;

  return 0;
}

// 입력 초기화
void init() {
  cin >> N >> M >> K;

  map.resize(N + 2, vector<int>(N + 2, 0));
  people_map.assign(N + 2, vector<int>(N + 2, 0));
  people.resize(M + 1, {0, 0, 0, 0, 0});
  exitPeople.resize(M + 1, false);

  // 미로 정보
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> map[i][j];
    }
  }

  // 참가자들 위치 정보
  for (int id = 1; id <= M; id++) {
    int row, col;
    cin >> row >> col;

    people_map[row][col] = id;
    people[id] = {id, row, col, 0, 0};

    cntNoExitPeople++;
  }

  // 출구 좌표 입력
  cin >> locExit.row >> locExit.col;
  map[locExit.row][locExit.col] = -1;

  return;
}

int calDist(int row, int col) {
  return abs(locExit.row - row) + abs(locExit.col - col);
}

void move(int id) {
  // 상-하-좌-우 순서로 이동
  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  Node now = {people[id].row, people[id].col};
  int now_dist = people[id].dist;
  bool isMove = false;

  for (int i = 0; i < 4; i++) {
    int ny = now.row + dy[i];
    int nx = now.col + dx[i];

    if (ny < 1 || ny > N || nx < 1 || nx > N) continue;  // 미로 범위 벗어남
    if (map[ny][nx] > 0) continue;                       // 벽 만나면 이동 불가

    int temp_dist = calDist(ny, nx);

    if (now_dist <= temp_dist)
      continue;  // 이동 후 출구까지 거리가 같거나 멀면 이동 불가

    now.row = ny;
    now.col = nx;
    now_dist = temp_dist;
    isMove = true;
    break;
  }

  // 움직였으면, 참가자 위치 정보 갱신
  if (isMove) {
    int cnt = people[id].mvCnt + 1;
    people[id] = {id, now.row, now.col, cnt, now_dist};

    // 탈출 여부 갱신
    if (now_dist == 0) {  // 출구에 도달했으면, 즉시 탈출
      exitPeople[id] = true;
      cntNoExitPeople--;
    }
  }

  return;
}

void rotate_map() {
  bool check = false;
  int lenRect = 0;
  Node start = {0, 0};

  for (int n = 2; n <= N; n++) {  // 정사각형 변의 길이
    // 시작 좌표 세팅
    for (int row = 1; row <= N - n + 1; row++) {
      for (int col = 1; col <= N - n + 1; col++) {
        // 범위 내에 참가자와 출구가 있는지 확인
        int cnt_people = 0;
        int cnt_exit = 0;
        for (int y = row; y < row + n; y++) {
          for (int x = col; x < col + n; x++) {
            if (people_map[y][x] != 0) cnt_people++;

            if (y == locExit.row && x == locExit.col) cnt_exit++;
          }
        }

        // 범위 내에 출구 1개와 참가자 1인 이상 있는 경우,
        if (cnt_people > 0 && cnt_exit > 0) {
          check = true;
          start.row = row;
          start.col = col;
          lenRect = n;
          break;
        }
      }

      if (check) break;
    }

    if (check) break;
  }

  if (check) {
    // 회전 시작
    vector<vector<int>> temp_map;
    vector<vector<int>> temp_people;
    temp_map.assign(lenRect, vector<int>(lenRect, 0));
    temp_people.assign(lenRect, vector<int>(lenRect, 0));

    // 맵 복사
    for (int i = 0; i < lenRect; i++) {
      for (int j = 0; j < lenRect; j++) {
        temp_map[i][j] = map[start.row + i][start.col + j];
        temp_people[i][j] = people_map[start.row + i][start.col + j];
      }
    }

    // 맵 회전
    rotatePeople.assign(M + 1, false);
    for (int i = 0; i < lenRect; i++) {
      for (int j = 0; j < lenRect; j++) {
        map[start.row + i][start.col + j] = temp_map[lenRect - j - 1][i];
        people_map[start.row + i][start.col + j] =
            temp_people[lenRect - j - 1][i];

        // 출구 좌표 갱신
        if (map[start.row + i][start.col + j] == -1) {
          locExit.row = start.row + i;
          locExit.col = start.col + j;
        }

        // 참가자 좌표 갱신
        if (people_map[start.row + i][start.col + j] != 0) {
          int person_row = people[people_map[start.row + i][start.col + j]].row;
          int person_col = people[people_map[start.row + i][start.col + j]].col;

          // 같은 위치에 여러 참가자가 있는 경우 고려
          for (int id = 1; id <= M; id++) {
            // 이미 한번이라도 회전했으면 제외
            if (rotatePeople[id]) continue;

            if (people[id].row == person_row && people[id].col == person_col) {
              rotatePeople[id] = true;
              people[id].row = start.row + i;
              people[id].col = start.col + j;
            }
          }
        }

        // 벽 내구도 갱신
        if (map[start.row + i][start.col + j] > 0) {
          map[start.row + i][start.col + j]--;
        }
      }
    }
  }
}