#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

struct CheckMax {
  int max_cnt;
  int max_deg;
  int max_y;
  int max_x;
};

int map[5][5];
int visited[5][5];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void rotate(int start_y, int start_x) {
  int temp[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      temp[i][j] = map[start_y + i][start_x + j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      map[start_y + i][start_x + j] = temp[2 - j][i];
    }
  }

  return;
}

void bfs(int y, int x, int* checkCnt) {
  int now_num = map[y][x];  // 탐색할 번호 체크
  int count = 1;

  queue<Node> que;
  que.push({y, x});

  visited[y][x] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
      if (map[ny][nx] != now_num) continue;
      if (visited[ny][nx] == 1) continue;

      que.push({ny, nx});
      visited[ny][nx] = 1;

      count++;
    }
  }

  if (count >= 3) *checkCnt += count;
}

void bfs2(int y, int x, int* now_count) {
  int now_num = map[y][x];  // 탐색할 번호 체크
  int count = 1;

  queue<Node> que;
  que.push({y, x});

  visited[y][x] = 1;

  vector<Node> checkNode;
  checkNode.push_back({y, x});

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
      if (map[ny][nx] != now_num) continue;
      if (visited[ny][nx] == 1) continue;

      que.push({ny, nx});
      visited[ny][nx] = 1;

      checkNode.push_back({ny, nx});

      count++;
    }
  }

  if (count >= 3) {
    *now_count += count;
    for (int i = 0; i < checkNode.size(); i++) {
      map[checkNode[i].y][checkNode[i].x] = 0;
    }
  }
}

int main() {
  int k, m;
  cin >> k >> m;

  vector<int> nums;  // 유물 개수
  nums.resize(m, 0);
  int num_cursor = 0;  // 유물 조각 위치

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> nums[i];
  }

  // for (int i = 0; i < 5; i++) {
  //	for (int j = 0; j < 5; j++) {
  //		cout << map[i][j] << " ";
  //	}
  //	cout << "\n";
  // }
  //
  // cout << "\n";
  //
  // rotate(1, 1);
  //
  // for (int i = 0; i < 5; i++) {
  //	for (int j = 0; j < 5; j++) {
  //		cout << map[i][j] << " ";
  //	}
  //	cout << "\n";
  // }
  //
  // cout << "\n";

  for (int turn = 0; turn < k; turn++) {
    // 아무것도 회전하지 않은 경우 체크
    int checkCnt = 0;
    fill(visited[0], visited[0] + 25, 0);  // 방문 배열 초기화
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (visited[i][j] == 0) continue;  // 이미 체크한 위치는 스킵
        bfs(i, j, &checkCnt);
      }
    }

    CheckMax result = {checkCnt, 0, 0, 0};  // MAX 체크

    // 회전하면서 체크 : ry, rx는 회전 시작점
    int now = 0;
    for (int ry = 0; ry < 3; ry++) {
      for (int rx = 0; rx < 3; rx++) {
        // 90도 회전 후 탐색 수행
        checkCnt = 0;                          // 카운팅 초기화
        fill(visited[0], visited[0] + 25, 0);  // 방문 배열 초기화
        rotate(ry, rx);
        for (int by = 0; by < 5; by++) {
          for (int bx = 0; bx < 5; bx++) {
            if (visited[by][bx] == 1) continue;
            bfs(by, bx, &checkCnt);
          }
        }
        if (result.max_cnt <= checkCnt) {  // 최대 값 체크
          if (result.max_cnt < checkCnt) {
            result.max_cnt = checkCnt;
            result.max_deg = 90;
            result.max_y = ry;
            result.max_x = rx;
          } else {
            if (result.max_deg > 90) {  // 각도 체크
              result.max_cnt = checkCnt;
              result.max_deg = 90;
              result.max_y = ry;
              result.max_x = rx;
            } else if (result.max_deg == 90) {
              if (result.max_x > rx) {
                result.max_cnt = checkCnt;
                result.max_deg = 90;
                result.max_y = ry;
                result.max_x = rx;
              } else if (result.max_x == rx) {
                if (result.max_y > ry) {
                  result.max_cnt = checkCnt;
                  result.max_deg = 90;
                  result.max_y = ry;
                  result.max_x = rx;
                }
              }
            }
          }
        }

        // 180도 회전 후 탐색 수행
        checkCnt = 0;                          // 카운팅 초기화
        fill(visited[0], visited[0] + 25, 0);  // 방문 배열 초기화
        rotate(ry, rx);
        for (int by = 0; by < 5; by++) {
          for (int bx = 0; bx < 5; bx++) {
            if (visited[by][bx] == 1) continue;
            bfs(by, bx, &checkCnt);
          }
        }
        if (result.max_cnt <= checkCnt) {  // 최대 값 체크
          if (result.max_cnt < checkCnt) {
            result.max_cnt = checkCnt;
            result.max_deg = 180;
            result.max_y = ry;
            result.max_x = rx;
          } else {
            if (result.max_deg > 180) {  // 각도 체크
              result.max_cnt = checkCnt;
              result.max_deg = 180;
              result.max_y = ry;
              result.max_x = rx;
            } else if (result.max_deg == 180) {
              if (result.max_x > rx) {
                result.max_cnt = checkCnt;
                result.max_deg = 180;
                result.max_y = ry;
                result.max_x = rx;
              } else if (result.max_x == rx) {
                if (result.max_y > ry) {
                  result.max_cnt = checkCnt;
                  result.max_deg = 180;
                  result.max_y = ry;
                  result.max_x = rx;
                }
              }
            }
          }
        }

        // 270도 회전 후 탐색 수행
        checkCnt = 0;                          // 카운팅 초기화
        fill(visited[0], visited[0] + 25, 0);  // 방문 배열 초기화
        rotate(ry, rx);
        for (int by = 0; by < 5; by++) {
          for (int bx = 0; bx < 5; bx++) {
            if (visited[by][bx] == 1) continue;
            bfs(by, bx, &checkCnt);
          }
        }
        if (result.max_cnt <= checkCnt) {  // 최대 값 체크
          if (result.max_cnt < checkCnt) {
            result.max_cnt = checkCnt;
            result.max_deg = 270;
            result.max_y = ry;
            result.max_x = rx;
          } else {
            if (result.max_deg > 270) {  // 각도 체크
              result.max_cnt = checkCnt;
              result.max_deg = 270;
              result.max_y = ry;
              result.max_x = rx;
            } else if (result.max_deg == 270) {
              if (result.max_x > rx) {
                result.max_cnt = checkCnt;
                result.max_deg = 270;
                result.max_y = ry;
                result.max_x = rx;
              } else if (result.max_x == rx) {
                if (result.max_y > ry) {
                  result.max_cnt = checkCnt;
                  result.max_deg = 270;
                  result.max_y = ry;
                  result.max_x = rx;
                }
              }
            }
          }
        }
        // 360도 회전 : 원 상태로 돌리기
        rotate(ry, rx);
      }
    }

    // ===== 디버깅 =====
    // cout << "\n";
    // for (int i = 0; i < 5; i++) {
    //	for (int j = 0; j < 5; j++) {
    //		cout << map[i][j] << " ";
    //	}
    //	cout << "\n";
    //}
    // cout << "\n";
    // ===== 디버깅 끝 =====

    if (result.max_cnt == 0) break;  // 획득 X -> 탐사 종료

    // 유물 지우기
    // 최대값으로 회전
    if (result.max_deg != 0) {
      for (int i = 0; i < result.max_deg / 90; i++) {
        rotate(result.max_y, result.max_x);
      }
    }

    // ===== 디버깅 =====
    // cout << "\n";
    // for (int i = 0; i < 5; i++) {
    //	for (int j = 0; j < 5; j++) {
    //		cout << map[i][j] << " ";
    //	}
    //	cout << "\n";
    //}
    // cout << "\n";
    // ===== 디버깅 끝 =====

    // 지우고 최대 점수 찾기
    int max_count = 0;
    while (1) {
      int now_count = 0;
      fill(visited[0], visited[0] + 25, 0);  // 방문 배열 초기화
      for (int by = 0; by < 5; by++) {
        for (int bx = 0; bx < 5; bx++) {
          bfs2(by, bx, &now_count);
        }
      }

      if (now_count == 0) break;  // 현재 턴 종료

      max_count += now_count;

      // ===== 디버깅 =====
      // cout << "\n";
      // for (int i = 0; i < 5; i++) {
      //	for (int j = 0; j < 5; j++) {
      //		cout << map[i][j] << " ";
      //	}
      //	cout << "\n";
      //}
      // cout << "\n";
      // ===== 디버깅 끝 =====

      // 유물 채우기
      for (int mx = 0; mx < 5; mx++) {
        for (int my = 4; my >= 0; my--) {
          if (map[my][mx] == 0) {
            map[my][mx] = nums[num_cursor];
            num_cursor++;
          }
        }
      }

      // ===== 디버깅 =====
      // cout << "\n";
      // for (int i = 0; i < 5; i++) {
      //	for (int j = 0; j < 5; j++) {
      //		cout << map[i][j] << " ";
      //	}
      //	cout << "\n";
      //}
      // cout << "\n";
      // ===== 디버깅 끝 =====
    }

    cout << max_count << " ";
  }

  return 0;
}
