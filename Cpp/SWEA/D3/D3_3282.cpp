#include <iostream>
#include <vector>

using namespace std;

struct goods {
  int vol;
  int cost;
};

int main() {
  int t;
  cin >> t;

  for (int test = 1; test <= t; test++) {
    int N, K;
    cin >> N >> K;

    vector<goods> list(N + 1);

    for (int i = 1; i <= N; i++) {
      int temp1, temp2;
      cin >> temp1 >> temp2;

      list[i] = {temp1, temp2};
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int n = 1; n <= N; n++) {
      for (int k = 0; k <= K; k++) {
        if (list[n].vol > k) {
          dp[n][k] = dp[n - 1][k];
        } else {
          dp[n][k] =
              max(dp[n - 1][k], dp[n - 1][k - list[n].vol] + list[n].cost);
        }
      }
    }

    cout << "#" << test << " " << dp[N][K] << endl;
  }

  return 0;
}