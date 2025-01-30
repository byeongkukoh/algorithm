#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  // int nums[1000000] = {};
  int temp;
  int max = -1000000, min = 1000000;

  for (int i = 0; i < n; i++) {
    cin >> temp;

    if (temp > max) {
      max = temp;
    }

    if (temp < min) {
      min = temp;
    }
  }

  cout << min << " " << max;

  return 0;
}