#include <iostream>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;

  char nums[101];
  cin >> nums;

  for (int i = 0; nums[i]; i++) {
    sum = sum + int(nums[i]) - 48;
  }

  cout << sum;

  return 0;
}