#include <iostream>
using namespace std;

int main() {
  int nums[9] = {0};
  for (int i = 0; i < 9; i++) {
    cin >> nums[i];
  }

  int max = 0, max_index;

  for (int i = 0; i < 9; i++) {
    if (nums[i] > max) {
      max = nums[i];
      max_index = i;
    }
  }

  cout << max << "\n" << max_index + 1;

  return 0;
}