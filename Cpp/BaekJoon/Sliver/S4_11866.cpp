#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> que;

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    que.push(i);
  }

  cout << "<";
  int cnt = 0;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    cnt++;

    if (cnt == k) {
      cout << now;
      cnt = 0;

      if (que.size() >= 1) {
        cout << ", ";
      }
    } else {
      que.push(now);
    }
  }

  cout << ">";

  return 0;
}