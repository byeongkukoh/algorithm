#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    long long dp[101] = {0};

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
      dp[i] = dp[i - 3] + dp[i - 2];
    }

    cout << dp[n] << "\n";
  }

  return 0;
}