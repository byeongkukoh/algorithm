#include <iostream>

using namespace std;

int main() {
  while (true) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    bool flag = false;
    if (a >= b && a >= c) {
      flag = (a * a == b * b + c * c);
    } else if (b >= a && b >= c) {
      flag = (b * b == a * a + c * c);
    } else {
      flag = (c * c == a * a + b * b);
    }

    if (flag) {
      cout << "right" << "\n";
    } else {
      cout << "wrong" << "\n";
    }
  }

  return 0;
}