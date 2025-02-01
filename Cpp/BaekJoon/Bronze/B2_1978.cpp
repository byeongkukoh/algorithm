#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;

  vector<int> vect(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> vect[i];
  }

  for (int i = 0; i < n; i++) {
    // 2 = 소수
    if (vect[i] == 1) {
      continue;
    }

    int j = 2;
    bool chk = true;

    while (j < vect[i]) {
      if (vect[i] % j == 0) {
        chk = false;
        break;
      }

      j++;
    }

    if (chk == true) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}