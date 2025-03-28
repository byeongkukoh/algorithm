#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num = 1;

  while (1) {
    int n;
    cin >> n;

    if (n == 0) return 0;

    vector<vector<int>> vect;
    vect.resize(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> vect[i][j];
      }
    }

    int start = vect[0][1];

    vector<vector<int>> dp;
    dp.resize(n, vector<int>(3, 0));

    dp[0][1] = vect[0][1];
    dp[0][2] = vect[0][1] + vect[0][2];

    dp[1][0] = dp[0][1] + vect[1][0];
    dp[1][1] = min(
        {dp[0][1] + vect[1][1], dp[1][0] + vect[1][1], dp[0][2] + vect[1][1]});
    dp[1][2] = min(
        {dp[0][1] + vect[1][2], dp[1][1] + vect[1][2], dp[0][2] + vect[1][2]});

    for (int i = 2; i < n; i++) {
      dp[i][0] = min({dp[i - 1][0] + vect[i][0], dp[i - 1][1] + vect[i][0]});
      dp[i][1] = min({dp[i - 1][0] + vect[i][1], dp[i - 1][1] + vect[i][1],
                      dp[i - 1][2] + vect[i][1], dp[i][0] + vect[i][1]});
      dp[i][2] = min({dp[i - 1][1] + vect[i][2], dp[i - 1][2] + vect[i][2],
                      dp[i][1] + vect[i][2]});
    }

    cout << num << ". " << dp[n - 1][1] << "\n";
    num++;
  }

  return 0;
}