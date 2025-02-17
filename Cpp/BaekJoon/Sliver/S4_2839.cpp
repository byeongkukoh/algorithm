#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt = 0;

  while (n > 0) {
    if (n % 5 == 0) {
      cnt += n / 5;
      n = n % 5;
      break;
    }

    n = n - 3;
    cnt++;
  }

  if (n != 0) {
    cnt = -1;
  }

  cout << cnt;

  return 0;
}