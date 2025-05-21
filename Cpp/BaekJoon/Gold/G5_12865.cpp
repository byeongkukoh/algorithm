#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> dp(k + 1, 0);  // dp[w] = 최대 가치

  for (int i = 0; i < n; i++) {
    int weight, value;
    cin >> weight >> value;

    for (int w = k; w >= weight; w--) {
      dp[w] = max(dp[w], dp[w - weight] + value);
    }
  }

  cout << dp[k];

  return 0;
}