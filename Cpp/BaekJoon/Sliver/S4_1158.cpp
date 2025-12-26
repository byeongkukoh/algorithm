#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  queue<int> que;
  for (int i = 0; i < n; i++) {
    que.push(i + 1);
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

      if (!que.empty()) cout << ", ";
    } else {
      que.push(now);
    }
  }

  cout << ">";

  return 0;
}