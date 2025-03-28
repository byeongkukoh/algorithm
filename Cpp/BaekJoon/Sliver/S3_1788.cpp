#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int size = abs(n);

  vector<long long> dp;
  dp.resize(size + 1);

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= size; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
  }

  if (n < 0 && n % 2 == 0) {
    cout << -1 << "\n";
    cout << dp[abs(n)];
  } else if (n == 0) {
    cout << 0 << "\n";
    cout << 0;
  } else {
    cout << 1 << "\n";
    cout << dp[abs(n)];
  }

  return 0;
}