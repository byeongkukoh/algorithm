class Solution {
 public:
  long long maxSumTrionic(vector<int>& nums) {
    int n = nums.size();
    long long INF = LLONG_MIN / 2;

    vector<vector<long long>> dp(3, vector<long long>(n, INF));

    long long result = INF;

    for (int i = 1; i < n; i++) {
      // 1. 첫 번째 상승: dp[0]][1]
      if (nums[i] - nums[i - 1] > 0) {
        dp[0][i] =
            max(dp[0][i - 1] + nums[i], (long long)nums[i] + nums[i - 1]);
      }

      // 2. 두 번째 하강: dp[1][i]
      if (nums[i] - nums[i - 1] < 0) {
        // 2-1. 상승하다가 하강하는 경우
        if (dp[0][i - 1] != INF) dp[1][i] = dp[0][i - 1] + nums[i];

        // 2-2. 계속 하강하는 경우
        if (dp[1][i - 1] != INF) dp[1][i] = dp[1][i - 1] + nums[i];
      }

      // 3. 다시 상승하는 경우
      if (nums[i] - nums[i - 1] > 0) {
        // 3-1. 하강하다가 상승하는 경우
        if (dp[1][i - 1] != INF) dp[2][i] = dp[1][i - 1] + nums[i];

        // 3-2. 계속 상승하는 경우
        if (dp[2][i - 1] != INF) dp[2][i] = dp[2][i - 1] + nums[i];
      }

      // 4. 정답 갱신
      result = max(result, dp[2][i]);
    }

    return result;
  }
};