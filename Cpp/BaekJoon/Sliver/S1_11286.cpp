#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

struct Data {
  int number;

  bool operator<(Data right) const {
    if (abs(number) > abs(right.number)) return true;
    if (abs(number) < abs(right.number)) return false;

    if (number > right.number) return true;
    if (number < right.number) return false;

    return false;
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  priority_queue<Data> pque;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 0) {
      if (pque.empty())
        cout << 0 << "\n";
      else {
        Data now = pque.top();
        pque.pop();
        cout << now.number << "\n";
      }
    } else {
      pque.push({x});
    }
  }

  return 0;
}