#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long dp[40] = {0};

  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }

  cout << dp[n];

  return 0;
}