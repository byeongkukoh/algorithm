#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

struct Coords {
  int row;
  int col;
  int time;
};

struct Cross {
  int num;
  char dir;
  int time1;
  int time2;
};

// 상 하 좌 우
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<string> MAP;
vector<vector<int>> visited;
vector<Cross> cross;

int n, m;

void FLOOD_FILL(int row, int col) {
  queue<Coords> que;
  que.push({row, col, 0});

  visited[row][col] = 0;

  while (!que.empty()) {
    Coords now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nrow = now.row + dy[i];
      int ncol = now.col + dx[i];
      int nextTime = now.time + 1;

      if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;
      if (MAP[nrow][ncol] == '.') continue;
      if (visited[nrow][ncol] != -1) continue;

      // 교차로 만났을 때 처리
      if (MAP[nrow][ncol] >= '0' && MAP[nrow][ncol] <= '9') {
        int crossNum = int(MAP[nrow][ncol]) - int('0');
        int period = cross[crossNum].time1 + cross[crossNum].time2;
        char currDir;

        if (cross[crossNum].dir == '-') {
          if ((nextTime % period) >= 1 &&
              (nextTime % period) <= cross[crossNum].time1) {
            currDir = '-';
          } else {
            currDir = '|';
          }
        } else {
          if ((nextTime % period) >= 1 &&
              (nextTime % period) <= cross[crossNum].time2) {
            currDir = '|';
          } else {
            currDir = '-';
          }
        }

        if ((i == 0 || i == 1) && currDir == '|') {
          que.push({nrow, ncol, nextTime});
          visited[nrow][ncol] = nextTime;
        } else if ((i == 2 || i == 3) && currDir == '-') {
          que.push({nrow, ncol, nextTime});
          visited[nrow][ncol] = nextTime;
        } else {
          que.push({now.row, now.col, nextTime});
        }

        continue;
      }

      // 교차로가 아닌 경우 처리
      visited[nrow][ncol] = nextTime;
      que.push({nrow, ncol, nextTime});
    }
  }

  return;
}

int main() {
  while (1) {
    Node START_STORE = {0, 0};
    Node END_STORE = {0, 0};

    cin >> n >> m;

    if (n == 0 && m == 0) break;

    MAP.clear();
    MAP.resize(n);

    visited.clear();
    visited.resize(n, vector<int>(m, -1));

    cross.clear();

    for (int i = 0; i < n; i++) {
      cin >> MAP[i];
    }

    int crossCNT = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (MAP[i][j] == 'A') {
          START_STORE = {i, j};
        }

        if (MAP[i][j] == 'B') {
          END_STORE = {i, j};
        }

        if (MAP[i][j] >= '0' && MAP[i][j] <= '9') crossCNT++;
      }
    }

    if (crossCNT != 0) {
      for (int i = 0; i < crossCNT; i++) {
        Cross temp;
        cin >> temp.num >> temp.dir >> temp.time1 >> temp.time2;

        cross.push_back(temp);
      }
    }

    FLOOD_FILL(START_STORE.row, START_STORE.col);

    if (visited[END_STORE.row][END_STORE.col] == -1) {
      cout << "impossible" << "\n";
    } else {
      cout << visited[END_STORE.row][END_STORE.col] << "\n";
    }
  }

  return 0;
}