#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int nums[10];

    for (int i = 0; i < 10; i++) {
      cin >> nums[i];
    }

    sort(nums, nums + 10);

    int sum = 0;
    for (int i = 1; i < 9; i++) {
      sum += nums[i];
    }

    double res = double(sum) / 8;

    if (int(res + 0.5) > int(res))
      res = int(res + 1);
    else
      res = int(res);

    cout << "#" << t + 1 << " " << res << "\n";
  }

  return 0;
}