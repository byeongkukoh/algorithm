#include <iostream>

using namespace std;

int main() {
  int C;
  cin >> C;

  int n = 1;

  while (C != 1) {
    n++;

    if (C % 2 == 0)
      C = C / 2;
    else
      C = C * 3 + 1;
  }

  cout << n;

  return 0;
}