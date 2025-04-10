#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Warrior {
  int id;
  int row;
  int col;
  int height;
  int width;
  int hp;
  int damage = 0;
  bool isLive = true;
};

int L, N, Q;  // 초기 입력값

vector<vector<int>> map;           // 맵 정보
vector<Warrior> warriors;          // 기사 정보
vector<vector<int>> warriors_map;  // 기사 배치 정보
vector<int> checkID;               // 이동가능 체크 여부

void init();                              // 초기화
bool checkMovable(int id, int dir);       // 이동 가능한지 체크
void move(int id, int dir, int comID);    // 이동
void dmgCheck(int id, int row, int col);  // 이동 후 데미지 체크

int main() {
  init();

  for (int q = 0; q < Q; q++) {
    int id, dir;
    cin >> id >> dir;  // dir = 0, 1, 2, 3 (상, 우, 하, 좌)

    // 명령 받은 기사가 죽었으면, 다음 명령 입력으로...
    if (!warriors[id - 1].isLive) continue;

    // 살아 있으면 이동 가능한지 체크
    checkID.assign(N, 0);
    bool isMove = checkMovable(id, dir);

    // 이동 불가면 다음 명령 입력으로...
    if (!isMove) continue;

    // 이동 가능하면
    for (int i = 0; i < N; i++) {
      // 이동한 기사에 대해서 좌표 이동
      if (checkID[i] == 1) {
        move(i + 1, dir, id);
      }
    }

    // 이동이 끝났으면, 기사 배치도 다시 작성
    warriors_map.assign(L + 2, vector<int>(L + 2, 0));
    for (int i = 0; i < N; i++) {
      Warrior now = warriors[i];

      if (!now.isLive) continue;

      for (int j = now.row; j < now.row + now.height; j++) {
        for (int k = now.col; k < now.col + now.width; k++) {
          warriors_map[j][k] = now.id;
        }
      }
    }
  }

  int total_dmg = 0;
  for (int i = 0; i < N; i++) {
    if (!warriors[i].isLive) continue;

    total_dmg += warriors[i].damage;
  }

  cout << total_dmg;

  return 0;
}

// 초기화 함수
void init() {
  cin >> L >> N >> Q;

  map.resize(L + 2, vector<int>(L + 2, 2));
  warriors_map.resize(L + 2, vector<int>(L + 2, 0));

  for (int i = 1; i <= L; i++) {
    for (int j = 1; j <= L; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    int id = i + 1;
    int row, col, height, width, hp;
    cin >> row >> col >> height >> width >> hp;

    warriors.push_back({id, row, col, height, width, hp});

    for (int j = row; j < row + height; j++) {
      for (int k = col; k < col + width; k++) {
        warriors_map[j][k] = id;
      }
    }
  }
}

// 이동 가능 여부 체크 함수
bool checkMovable(int id, int dir) {
  // 이미 검사한 기사 체크 제외
  if (checkID[id - 1] == 1) return true;

  struct Warrior info = warriors[id - 1];
  checkID[id - 1] = 1;

  // 위쪽 이동 가능 여부 체크
  if (dir == 0) {
    // 벽을 만나면 이동 불가
    for (int i = 0; i < info.width; i++) {
      if (map[info.row - 1][info.col + i] == 2) return false;
    }

    // 다른 기사를 만나면 다른 기사도 이동 가능한지 체크
    for (int i = 0; i < info.width; i++) {
      if (warriors_map[info.row - 1][info.col + i] != 0) {
        int new_id = warriors_map[info.row - 1][info.col + i];

        if (!warriors[new_id - 1].isLive) continue;

        bool check = checkMovable(new_id, dir);
        if (!check) return false;
      }
    }

    return true;

  } else if (dir == 1) {  // 오른쪽 이동 가능 여부 체크
    // 벽을 만나면 이동 불가
    for (int i = 0; i < info.height; i++) {
      if (map[info.row + i][info.col + info.width] == 2) return false;
    }

    // 다른 기사를 만나면 다른 기사도 이동 가능한지 체크
    for (int i = 0; i < info.height; i++) {
      if (warriors_map[info.row + i][info.col + info.width] != 0) {
        int new_id = warriors_map[info.row + i][info.col + info.width];

        // 다음 기사가 죽어있으면 이동 가능
        if (!warriors[new_id - 1].isLive) continue;

        bool check = checkMovable(new_id, dir);
        if (!check) return false;
      }
    }

    // 모든 조건에 걸리지 않으면 이동 가능
    return true;
  } else if (dir == 2) {  // 아래쪽 이동 가능 여부 체크
    // 벽을 만나면 이동 불가
    for (int i = 0; i < info.width; i++) {
      if (map[info.row + info.height][info.col + i] == 2) return false;
    }

    // 다른 기사를 만나면 다른 기사도 이동 가능한지 체크
    for (int i = 0; i < info.width; i++) {
      if (warriors_map[info.row + info.height][info.col + i] != 0) {
        int new_id = warriors_map[info.row + info.height][info.col + i];

        if (!warriors[new_id - 1].isLive) continue;

        bool check = checkMovable(new_id, dir);
        if (!check) return false;
      }
    }

    return true;

  } else if (dir == 3) {  // 왼쪽 이동 가능 여부 체크
    // 벽을 만나면 이동 불가
    for (int i = 0; i < info.height; i++) {
      if (map[info.row + i][info.col - 1] == 2) return false;
    }

    // 다른 기사를 만나면 다른 기사도 이동 가능한지 체크
    for (int i = 0; i < info.height; i++) {
      if (warriors_map[info.row + i][info.col - 1] != 0) {
        int new_id = warriors_map[info.row + i][info.col - 1];

        // 다음 기사가 죽어있으면 이동 가능
        if (!warriors[new_id - 1].isLive) continue;

        bool check = checkMovable(new_id, dir);
        if (!check) return false;
      }
    }

    // 모든 조건에 걸리지 않으면 이동 가능
    return true;
  }

  printf("입력오류\n");

  return false;
}

void move(int id, int dir, int comID) {
  if (dir == 0) {  // 위쪽 이동
    warriors[id - 1].row -= 1;
  } else if (dir == 1) {  // 오른쪽 이동
    warriors[id - 1].col += 1;
  } else if (dir == 2) {  // 아래쪽 이동
    warriors[id - 1].row += 1;
  } else if (dir == 3) {  // 왼쪽 이동
    warriors[id - 1].col -= 1;
  } else {
    return;
  }

  if (id != comID) {
    dmgCheck(id, warriors[id - 1].row, warriors[id - 1].col);
  }

  return;
}

void dmgCheck(int id, int row, int col) {
  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  struct Node {
    int y, x;
  };

  vector<vector<int>> visited;
  visited.assign(L + 2, vector<int>(L + 2, 0));

  queue<Node> que;
  que.push({row, col});

  visited[row][col] = 1;

  int bomb = 0;  // 함정 개수 체크

  if (map[row][col] == 1) {
    bomb++;
  }

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (visited[ny][nx] != 0) continue;
      if (ny < row || nx < col || ny >= row + warriors[id - 1].height ||
          nx >= col + warriors[id - 1].width)
        continue;

      visited[ny][nx] = 1;
      que.push({ny, nx});

      if (map[ny][nx] == 1) {
        bomb++;
      }
    }
  }

  warriors[id - 1].damage += bomb;
  warriors[id - 1].hp -= bomb;

  if (warriors[id - 1].hp <= 0) {
    warriors[id - 1].isLive = false;
  }
}