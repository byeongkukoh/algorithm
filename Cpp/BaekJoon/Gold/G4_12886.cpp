#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
  int a;
  int b;
};

int visited[1500][1500];

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int sum = a + b + c;

  if (sum % 3 != 0) {
    cout << 0;
    return 0;
  }

  visited[a][b] = 1;

  queue<State> que;
  que.push({a, b});

  while (!que.empty()) {
    State now = que.front();
    que.pop();

    int x = now.a;
    int y = now.b;
    int z = sum - now.a - now.b;

    if (x == y && y == z) {
      cout << 1;
      return 0;
    }

    if (x != y) {
      int nx = x < y ? x * 2 : x - y;
      int ny = x < y ? y - x : y * 2;
      int nz = sum - nx - ny;

      if (nx >= 0 && ny >= 0 && nx < 1500 && ny < 1500 &&
          visited[nx][ny] == 0) {
        visited[nx][ny] = 1;
        que.push({nx, ny});
      }
    }

    if (x != z) {
      int nx = x < z ? x * 2 : x - z;
      int ny = y;
      int nz = sum - nx - ny;

      if (nx >= 0 && ny >= 0 && nx < 1500 && ny < 1500 &&
          visited[nx][ny] == 0) {
        visited[nx][ny] = 1;
        que.push({nx, ny});
      }
    }

    if (y != z) {
      int nx = x;
      int ny = y < z ? y * 2 : y - z;
      int nz = sum - nx - ny;

      if (nx >= 0 && ny >= 0 && nx < 1500 && ny < 1500 &&
          visited[nx][ny] == 0) {
        visited[nx][ny] = 1;
        que.push({nx, ny});
      }
    }
  }

  cout << 0;

  return 0;
}