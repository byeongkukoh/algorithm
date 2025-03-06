#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int pos;
  int time;

  bool operator<(Node right) const {
    if (time > right.time) return true;
    if (time < right.time) return false;

    return false;
  }
};

int find_time[100001];

int main() {
  int n, k;
  cin >> n >> k;

  fill(find_time, find_time + 100001, -1);

  priority_queue<Node> que;
  que.push({n, 0});

  find_time[n] = 0;

  while (!que.empty()) {
    Node now = que.top();
    que.pop();

    for (int i = 0; i < 3; i++) {
      int next, nexttime;

      if (i == 0) {  // 1칸 전진
        next = now.pos + 1;
        nexttime = now.time + 1;
      } else if (i == 1) {  // 1칸 후진
        next = now.pos - 1;
        nexttime = now.time + 1;
      } else {  // 순간이동
        next = now.pos * 2;
        nexttime = now.time;
      }

      if (next < 0 || next >= 100001) continue;
      if (find_time[next] != -1 && find_time[next] <= nexttime) continue;

      find_time[next] = nexttime;
      que.push({next, nexttime});
    }
  }

  cout << find_time[k];

  return 0;
}