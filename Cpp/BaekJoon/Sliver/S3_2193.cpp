#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> dp(n + 1);

  if (n >= 1) dp[1] = 1;
  if (n >= 2) dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }

  cout << dp[n];

  return 0;
}