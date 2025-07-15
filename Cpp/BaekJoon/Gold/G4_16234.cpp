#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int N, L, R;
vector<vector<int>> map;
vector<vector<int>> temp;

bool check = true;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int row, int col) {
  vector<Node> coord;
  queue<Node> que;
  que.push({row, col});

  int sum_p = map[row][col];
  temp[row][col] = map[row][col];

  coord.push_back({row, col});

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = now.x + dx[i];
      int ny = now.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (temp[ny][nx] != -1) continue;
      if (abs(map[ny][nx] - map[now.y][now.x]) >= L &&
          abs(map[ny][nx] - map[now.y][now.x]) <= R) {
        check = true;

        sum_p += map[ny][nx];
        temp[ny][nx] = map[ny][nx];
        coord.push_back({ny, nx});
        que.push({ny, nx});
      }
    }

    int val = sum_p / coord.size();

    for (int i = 0; i < coord.size(); i++) {
      temp[coord[i].y][coord[i].x] = val;
    }
  }
}

int main() {
  cin >> N >> L >> R;

  map.resize(N, vector<int>(N, 0));
  temp.resize(N, vector<int>(N, -1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int day = 0;

  while (check) {
    check = false;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (temp[i][j] != -1) continue;

        bfs(i, j);
      }
    }

    if (check) {
      day++;
      map = temp;

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          temp[i][j] = -1;
        }
      }
    }
  }

  cout << day;

  return 0;
}