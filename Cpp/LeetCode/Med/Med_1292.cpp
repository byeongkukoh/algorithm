class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int n = mat.size();
    int m = mat[0].size();

    // 누적합 계산
    vector<vector<long long>> totalSum(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        totalSum[i][j] = totalSum[i][j - 1] + totalSum[i - 1][j] -
                         totalSum[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    for (int k = min(n, m); k >= 1; k--) {
      for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
          long long total = totalSum[i + k][j + k] - totalSum[i][j + k] -
                            totalSum[i + k][j] + totalSum[i][j];

          if (total <= threshold) return k;
        }
      }
    }

    return 0;
  }
};