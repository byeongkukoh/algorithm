#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coord {
  int row;
  int col;
};

int N, L, R;

vector<vector<int>> map;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool bfs(int row, int col, vector<vector<int>>& temp) {
  vector<Coord> checkList;

  queue<Coord> que;
  que.push({row, col});

  temp[row][col] = map[row][col];
  checkList.push_back({row, col});

  int sumPeople = map[row][col];

  while (!que.empty()) {
    Coord now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (temp[ny][nx] != -1) continue;

      int diff = abs(map[now.row][now.col] - map[ny][nx]);

      if (diff >= L && diff <= R) {
        sumPeople += map[ny][nx];

        que.push({ny, nx});
        temp[ny][nx] = map[ny][nx];

        checkList.push_back({ny, nx});
      }
    }
  }

  if (checkList.size() == 1) return false;

  for (int i = 0; i < checkList.size(); i++) {
    temp[checkList[i].row][checkList[i].col] = sumPeople / checkList.size();
  }

  return true;
}

int main() {
  cin >> N >> L >> R;

  map.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int days = 0;
  bool check = true;  // 인구 이동이 일어났는지 체크

  while (check) {
    check = false;

    // 임시 배열 생성
    vector<vector<int>> temp(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (temp[i][j] != -1) continue;

        if (bfs(i, j, temp)) check = true;
      }
    }

    if (check) {
      days++;

      map = temp;  // 인구수 동기화
    }
  }

  cout << days;

  return 0;
}

// #include <cmath>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct Node {
//   int y;
//   int x;
// };

// int N, L, R;
// vector<vector<int>> map;
// vector<vector<int>> temp;

// bool check = true;

// int dy[] = {-1, 1, 0, 0};
// int dx[] = {0, 0, -1, 1};

// void bfs(int row, int col) {
//   vector<Node> coord;
//   queue<Node> que;
//   que.push({row, col});

//   int sum_p = map[row][col];
//   temp[row][col] = map[row][col];

//   coord.push_back({row, col});

//   while (!que.empty()) {
//     Node now = que.front();
//     que.pop();

//     for (int i = 0; i < 4; i++) {
//       int nx = now.x + dx[i];
//       int ny = now.y + dy[i];

//       if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//       if (temp[ny][nx] != -1) continue;
//       if (abs(map[ny][nx] - map[now.y][now.x]) >= L &&
//           abs(map[ny][nx] - map[now.y][now.x]) <= R) {
//         check = true;

//         sum_p += map[ny][nx];
//         temp[ny][nx] = map[ny][nx];
//         coord.push_back({ny, nx});
//         que.push({ny, nx});
//       }
//     }

//     int val = sum_p / coord.size();

//     for (int i = 0; i < coord.size(); i++) {
//       temp[coord[i].y][coord[i].x] = val;
//     }
//   }
// }

// int main() {
//   cin >> N >> L >> R;

//   map.resize(N, vector<int>(N, 0));
//   temp.resize(N, vector<int>(N, -1));

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       cin >> map[i][j];
//     }
//   }

//   int day = 0;

//   while (check) {
//     check = false;

//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < N; j++) {
//         if (temp[i][j] != -1) continue;

//         bfs(i, j);
//       }
//     }

//     if (check) {
//       day++;
//       map = temp;

//       for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//           temp[i][j] = -1;
//         }
//       }
//     }
//   }

//   cout << day;

//   return 0;
// }