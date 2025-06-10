#include <iostream>
#include <string>

using namespace std;

int main() {
  string ISBN;
  cin >> ISBN;

  int sum_res = 0;
  int weight = -1;
  int pos = -1;

  for (int i = 0; i < ISBN.length(); i++) {
    if (ISBN[i] == '*') {
      pos = i;
      if (i % 2 == 0) {
        weight = 1;
      } else {
        weight = 3;
      }

    } else {
      if (i % 2 == 0) {
        sum_res += int(ISBN[i] - '0');
      } else {
        sum_res += int(ISBN[i] - '0') * 3;
      }
    }
  }

  int res = 0;

  for (int i = 0; i < 10; i++) {
    if ((sum_res + weight * i) % 10 == 0) {
      res = i;
      break;
    }
  }

  cout << res;

  return 0;
}