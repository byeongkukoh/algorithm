#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> stair;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    stair.push_back(temp);
  }

  vector<int> dp;  // i번째 계단까지 올라왔을 때의 최대 점수

  if (n == 1)
    cout << stair[0];

  else if (n == 2)
    cout << stair[0] + stair[1];
  else {
    dp.resize(n);

    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++) {
      dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << dp[n - 1];
  }

  return 0;
}