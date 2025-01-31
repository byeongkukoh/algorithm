#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int result = a * b * c;
  int nums[10] = {0};

  while (result > 0) {
    nums[result % 10]++;
    result = result / 10;
  }

  for (int i = 0; i < 10; i++) {
    cout << nums[i] << "\n";
  }

  return 0;
}