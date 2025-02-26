#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Data {
  string number;

  bool operator<(Data right) const {
    if (number.length() > right.number.length()) return true;
    if (number.length() < right.number.length()) return false;

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
    string x;
    cin >> x;

    if (x == "0") {
      if (pque.empty()) {
        cout << 0 << "\n";
      } else {
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