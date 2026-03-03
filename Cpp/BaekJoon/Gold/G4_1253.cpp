#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> nums(N);
  for (int i = 0; i < N; i++) cin >> nums[i];

  sort(nums.begin(), nums.end());

  int result = 0;

  for (int i = 0; i < N; i++) {
    int target = nums[i];

    int lo = 0;
    int hi = N - 1;

    while (lo < hi) {
      if (lo == i) {
        lo++;
        continue;
      }

      if (hi == i) {
        hi--;
        continue;
      }

      int temp = nums[lo] + nums[hi];
      if (temp == target) {
        result++;
        break;
      } else if (temp > target) {
        hi--;
      } else {
        lo++;
      }
    }
  }

  cout << result;

  return 0;
}