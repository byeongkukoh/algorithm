#include <iostream>
#include <vector>

using namespace std;

int dy[][4] = {
    // # # # #
    {0, 0, 0, 0},
    {0, 1, 2, 3},

    // # #
    // # #
    {0, 0, 1, 1},

    // #
    // # # # #
    {0, 1, 1, 1},
    {1, 1, 1, 0},
    {0, 0, 1, 2},
    {0, 0, 1, 2},
    {0, 0, 0, 1},
    {1, 0, 0, 0},
    {0, 1, 2, 2},
    {0, 1, 2, 2},

    // #
    // # #
    //   #
    {0, 1, 1, 2},
    {0, 1, 1, 2},
    {1, 1, 0, 0},
    {0, 0, 1, 1},

    //   #
    // # # #
    {0, 1, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 1, 0},
    {1, 0, 1, 2}};

int dx[][4] = {
    // # # # #
    {0, 1, 2, 3},
    {0, 0, 0, 0},

    // # #
    // # #
    {0, 1, 0, 1},

    // #
    // # # # #
    {0, 0, 1, 2},
    {0, 1, 2, 2},
    {0, 1, 0, 0},
    {0, 1, 1, 1},
    {0, 1, 2, 2},
    {0, 0, 1, 2},
    {1, 1, 1, 0},
    {0, 0, 0, 1},

    // #
    // # #
    //   #
    {0, 0, 1, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 2},
    {0, 1, 1, 2},

    //   #
    // # # #
    {1, 0, 1, 2},
    {0, 0, 1, 0},
    {0, 1, 1, 2},
    {0, 1, 1, 1}};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> sc;
  sc.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> sc[i][j];
    }
  }

  int answer = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 19; k++) {
        int now = 0;

        for (int dir = 0; dir < 4; dir++) {
          int ny = i + dy[k][dir];
          int nx = j + dx[k][dir];

          if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

          now += sc[ny][nx];
        }

        if (now > answer) answer = now;
      }
    }
  }

  cout << answer;

  return 0;
}