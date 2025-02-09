#include <iostream>
#include <string>

using namespace std;

int main() {
  string str[3];
  int idx, nums;

  for (int i = 0; i < 3; i++) {
    cin >> str[i];
    if (str[i][0] >= '0' && str[i][0] <= '9') {
      idx = i;
      nums = stoi(str[i]);
    }
  }

  int ans;

  if (idx == 2) {
    ans = nums + 1;
  } else if (idx == 1) {
    ans = nums + 2;
  } else {
    ans = nums + 3;
  }

  if (ans % 3 == 0 && ans % 5 == 0) {
    cout << "FizzBuzz";
  } else if (ans % 3 == 0) {
    cout << "Fizz";
  } else if (ans % 5 == 0) {
    cout << "Buzz";
  } else {
    cout << ans;
  }

  return 0;
}