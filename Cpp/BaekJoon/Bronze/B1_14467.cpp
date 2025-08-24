#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> cows;  // 번호, 위치

  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int cow, loc;
    cin >> cow >> loc;

    if (cows.find(cow) != cows.end()) {
      if (cows[cow] != loc) {
        cnt++;
        cows[cow] = loc;
      }
    } else {
      cows[cow] = loc;
    }
  }

  cout << cnt;

  return 0;
}