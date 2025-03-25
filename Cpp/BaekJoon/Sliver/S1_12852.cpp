#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> path;

int main() {
  int n;
  cin >> n;

  dp.resize(n + 1, 0);
  path.resize(n + 1, 0);

  dp[1] = 0;
  path[1] = 1;

  for (int i = 2; i <= n; i++) {
    // 1씩 증가
    dp[i] = dp[i - 1] + 1;
    path[i] = i - 1;

    // 2로 나누어 떨어지는 경우,
    if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
      dp[i] = dp[i / 2] + 1;
      path[i] = i / 2;
    }

    // 3으로 나누어 떨어지는 경우,
    if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
      dp[i] = dp[i / 3] + 1;
      path[i] = i / 3;
    }
  }

  cout << dp[n] << "\n";

  while (1) {
    if (n == 1) {
      cout << n;
      break;
    }

    cout << n << " ";

    n = path[n];
  }

  return 0;
}