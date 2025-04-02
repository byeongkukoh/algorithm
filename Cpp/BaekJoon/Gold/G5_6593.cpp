#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int l;
  int r;
  int c;
};

int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};

int main() {
  while (1) {
    int L, R, C;
    cin >> L >> R >> C;

    if (L == 0 && R == 0 && C == 0) break;

    vector<vector<vector<int>>> bdg;
    vector<vector<vector<int>>> visited;

    bdg.assign(L, vector<vector<int>>(R, vector<int>(C, 0)));
    visited.assign(L, vector<vector<int>>(R, vector<int>(C, -1)));

    Node start = {0, 0, 0};
    Node exit = {0, 0, 0};

    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        string temp;
        cin >> temp;

        for (int k = 0; k < C; k++) {
          if (temp[k] == 'S') {
            start = {i, j, k};
            bdg[i][j][k] = 0;
          }

          if (temp[k] == '.') {
            bdg[i][j][k] = 0;
          }

          if (temp[k] == '#') {
            bdg[i][j][k] = 1;
          }

          if (temp[k] == 'E') {
            exit = {i, j, k};
            bdg[i][j][k] = 0;
          }
        }
      }
    }

    queue<Node> que;
    que.push(start);

    visited[start.l][start.r][start.c] = 0;

    while (!que.empty()) {
      Node now = que.front();
      que.pop();

      for (int i = 0; i < 6; i++) {
        int nz = now.l + dz[i];
        int ny = now.r + dy[i];
        int nx = now.c + dx[i];

        if (nz >= L || ny >= R || nx >= C || nz < 0 || ny < 0 || nx < 0)
          continue;
        if (bdg[nz][ny][nx] == 1) continue;
        if (visited[nz][ny][nx] != -1 &&
            visited[nz][ny][nx] <= visited[now.l][now.r][now.c] + 1)
          continue;

        visited[nz][ny][nx] = visited[now.l][now.r][now.c] + 1;
        que.push({nz, ny, nx});
      }
    }

    if (visited[exit.l][exit.r][exit.c] == -1) {
      cout << "Trapped!\n";
    } else {
      cout << "Escaped in " << visited[exit.l][exit.r][exit.c]
           << " minute(s).\n";
    }
  }

  return 0;
}