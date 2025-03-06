#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int dist[100001];

int main() {
  int n, k;
  cin >> n >> k;

  fill(dist, dist + 100001, -1);

  queue<int> que;
  que.push(n);

  dist[n] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < 3; i++) {
      int next;
      if (i == 0) next = now + 1;  // 1칸 전진
      if (i == 1) next = now - 1;  // 1칸 후진
      if (i == 2) next = now * 2;  // 순간이동

      if (next < 0 || next >= 100001) continue;
      if (dist[next] != -1) continue;

      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }

  cout << dist[k];

  return 0;
}