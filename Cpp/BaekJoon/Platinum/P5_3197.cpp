#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int R, C;

Node swan1 = {-1, -1};
Node swan2 = {-1, -1};

vector<string> map;
vector<vector<bool>> swanVisited;
vector<vector<bool>> waterVisited;

queue<Node> swanQ, swanNQ;
queue<Node> waterQ, waterNQ;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool swanMove() {
  while (!swanQ.empty()) {
    Node now = swanQ.front();
    swanQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
      if (swanVisited[ny][nx]) continue;

      if (map[ny][nx] == 'L' && swan2.row == ny && swan2.col == nx) {
        return true;
      }

      swanVisited[ny][nx] = true;

      if (map[ny][nx] == '.') {
        swanQ.push({ny, nx});
      }

      if (map[ny][nx] == 'X') {
        swanNQ.push({ny, nx});
      }
    }
  }

  return false;
}

void iceMelt() {
  while (!waterQ.empty()) {
    Node now = waterQ.front();
    waterQ.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
      if (waterVisited[ny][nx]) continue;

      if (map[ny][nx] == 'X') {
        map[ny][nx] = '.';
        waterVisited[ny][nx] = true;
        waterNQ.push({ny, nx});
      }
    }
  }

  return;
}

int main() {
  cin >> R >> C;

  map.resize(R);
  swanVisited.resize(R, vector<bool>(C, false));
  waterVisited.resize(R, vector<bool>(C, false));

  for (int i = 0; i < R; i++) {
    cin >> map[i];

    for (int j = 0; j < C; j++) {
      if (map[i][j] == 'L') {
        if (swan1.row == -1 && swan1.col == -1) {
          swan1.row = i;
          swan1.col = j;
        } else {
          swan2.row = i;
          swan2.col = j;
        }
      }

      if (map[i][j] != 'X') {
        waterQ.push({i, j});
        waterVisited[i][j] = true;
      }
    }
  }

  swanQ.push(swan1);
  swanVisited[swan1.row][swan1.col] = true;

  int day = 0;
  while (true) {
    if (swanMove()) break;

    iceMelt();

    swap(swanQ, swanNQ);
    swap(waterQ, waterNQ);

    day++;
  }

  cout << day;

  return 0;
}