#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> weight(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> weight[n];
  }

  vector<int> dp(K + 1, 0);
  dp[0] = 1;
  for (int n = 0; n < N; n++) {
    for (int k = weight[n]; k <= K; k++) {
      dp[k] += dp[k - weight[n]];
    }
  }

  cout << dp[K] << "\n";

  return 0;
}