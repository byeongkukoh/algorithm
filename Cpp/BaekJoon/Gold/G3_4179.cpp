#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int map[1005][1005];
int visited[1005][1005];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<Node> jihoon;
queue<Node> fire;

int r, c;
bool isPossible = false;
int resTime = 0;

int main() {
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < c; j++) {
      if (temp[j] == '#') {
        map[i][j] = 1;  // 벽 = # = 1
      } else {
        if (temp[j] == 'J') {
          jihoon.push({i, j});

          if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
            isPossible = true;
            resTime = 1;
          }
        } else if (temp[j] == 'F') {
          fire.push({i, j});
        }
      }
    }
  }

  if (isPossible) {
    cout << resTime;
    return 0;
  }

  int time = 0;

  while (!jihoon.empty()) {
    if (isPossible) break;

    time++;
    int fireCnt = fire.size();
    while (fireCnt--) {
      Node fire_now = fire.front();
      fire.pop();

      visited[fire_now.row][fire_now.col] = -1;

      for (int i = 0; i < 4; i++) {
        int ny = fire_now.row + dy[i];
        int nx = fire_now.col + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (map[ny][nx] == 1) continue;
        if (visited[ny][nx] == -1) continue;

        visited[ny][nx] = -1;
        fire.push({ny, nx});
      }
    }

    int jihoonCnt = jihoon.size();
    while (jihoonCnt--) {
      Node jihoon_now = jihoon.front();
      jihoon.pop();

      visited[jihoon_now.row][jihoon_now.col] = 1;

      for (int i = 0; i < 4; i++) {
        int ny = jihoon_now.row + dy[i];
        int nx = jihoon_now.col + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (map[ny][nx] == 1) continue;
        if (visited[ny][nx] == -1) continue;
        if (visited[ny][nx] == 1) continue;

        visited[ny][nx] = 1;
        jihoon.push({ny, nx});

        if (ny == 0 || ny == r - 1 || nx == 0 || nx == c - 1) {
          isPossible = true;
          resTime = time;
        }
      }
    }
  }

  if (isPossible)
    cout << resTime + 1;
  else
    cout << "IMPOSSIBLE";

  return 0;
}