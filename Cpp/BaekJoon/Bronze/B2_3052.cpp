#include <iostream>

using namespace std;

int main() {
  int nums[10];
  for (int i = 0; i < 10; i++) {
    cin >> nums[i];
  }

  int dat[42] = {0};

  for (int i = 0; i < 10; i++) {
    dat[nums[i] % 42] = 1;
  }

  int cnt = 0;

  for (int i = 0; i < 42; i++) {
    if (dat[i] == 1) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}