#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  priority_queue<int> pque;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 0) {
      if (pque.empty())
        cout << 0 << "\n";
      else {
        cout << pque.top() << "\n";
        pque.pop();
      }
    } else {
      pque.push(x);
    }
  }

  return 0;
}