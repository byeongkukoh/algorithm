#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int map[101] = {0};
  int ladder[101] = {0};
  int snake[101] = {0};

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int from, to;
    cin >> from >> to;

    ladder[from] = to;
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    snake[from] = to;
  }

  int start = 1;
  queue<int> que;
  que.push(start);

  map[start] = 1;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 1; i <= 6; i++) {
      int next = now + i;

      if (next > 100) continue;
      if (map[next] != 0 && map[next] <= map[now] + 1) continue;

      map[next] = map[now] + 1;

      if (ladder[next] != 0) {
        next = ladder[next];
        if (map[next] != 0 && map[next] <= map[now] + 1) continue;

        map[next] = map[now] + 1;
      }

      if (snake[next] != 0) {
        next = snake[next];
        if (map[next] != 0 && map[next] <= map[now] + 1) continue;

        map[next] = map[now] + 1;
      }

      que.push(next);
    }
  }

  cout << map[100] - 1;

  return 0;
}