#include <iostream>
#include <queue>

using namespace std;

struct Docs {
  int nums;
  int pri;
};

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    queue<Docs> que;
    priority_queue<int> pque;

    int n, key;
    cin >> n >> key;

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;

      que.push({i, temp});
      pque.push(temp);
    }

    int cnt = 0;
    while (!que.empty()) {
      Docs now = que.front();
      que.pop();

      if (now.pri == pque.top()) {
        pque.pop();
        cnt++;

        if (now.nums == key) {
          cout << cnt << "\n";
        }
      } else {
        que.push(now);
      }
    }
  }

  return 0;
}