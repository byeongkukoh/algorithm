#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string binary_num;
  cin >> binary_num;

  int len = binary_num.length();

  int start;
  if (len % 3 == 0) {
    start = 0;
  } else if (len % 3 == 1) {
    cout << int(binary_num[0] - '0');
    start = 1;
  } else {
    cout << int((binary_num[0] - '0') * 2) + int(binary_num[1] - '0');
    start = 2;
  }

  for (int i = start; i < len; i = i + 3) {
    cout << int((binary_num[i] - '0') * 4) +
                int((binary_num[i + 1] - '0') * 2) +
                int(binary_num[i + 2] - '0');
  }

  return 0;
}