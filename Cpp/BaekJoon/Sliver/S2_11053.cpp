#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> dp(n, 1);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }

    if (dp[i] > ans) {
      ans = dp[i];
    }
  }

  cout << ans;

  return 0;
}