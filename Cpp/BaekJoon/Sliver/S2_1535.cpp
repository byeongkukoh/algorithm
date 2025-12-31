#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> L(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> L[i];
  }

  vector<int> J(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> J[i];
  }

  int dp[100] = {0};

  for (int i = 1; i <= n; i++) {
    if (L[i] >= 100) continue;

    for (int used_hp = 99; used_hp >= L[i]; used_hp--) {
      dp[used_hp] = max(dp[used_hp], dp[used_hp - L[i]] + J[i]);
    }
  }

  int result = 0;
  for (int i = 0; i < 100; i++) {
    result = max(result, dp[i]);
  }

  cout << result;

  return 0;
}