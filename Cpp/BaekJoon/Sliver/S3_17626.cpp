#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int curr;
  int cnt;
};

int main() {
  int n;
  cin >> n;

  vector<bool> visited(n + 1, false);

  queue<Node> que;
  que.push({n, 0});

  while (!que.empty()) {
    int cur = que.front().curr;
    int cnt = que.front().cnt;
    que.pop();

    for (int i = 1; i * i <= cur; i++) {
      int next = cur - (i * i);

      if (!visited[next]) {
        if (next == 0) {
          cout << cnt + 1;
          return 0;
        }

        visited[next] = true;
        que.push({next, cnt + 1});
      }
    }
  }

  return 0;
}