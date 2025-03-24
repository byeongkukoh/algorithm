#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> map;
  map.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cin >> map[i][j];
    }
  }

  vector<vector<int>> dp;
  dp.resize(n, vector<int>(n, 0));

  dp[0][0] = map[0][0];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j == 0)
        dp[i][j] = dp[i - 1][j] + map[i][j];
      else if (j == i)
        dp[i][j] = dp[i - 1][j - 1] + map[i][j];
      else
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
    }
  }

  int result = 0;

  for (int i = 0; i < n; i++) {
    if (result < dp[n - 1][i]) {
      result = dp[n - 1][i];
    }
  }

  cout << result;

  return 0;
}