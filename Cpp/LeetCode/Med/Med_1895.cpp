class Solution {
 public:
  bool isCheck(vector<vector<int>>& grid, int k, int r, int c) {
    // 기준
    long long targetSum = 0;
    for (int j = 0; j < k; j++) targetSum += grid[r][c + j];

    // 1. 행 검사
    for (int i = 0; i < k; i++) {
      long long currentSum = 0;
      for (int j = 0; j < k; j++) currentSum += grid[r + i][c + j];
      if (currentSum != targetSum) return false;
    }

    // 2. 열 검사
    for (int j = 0; j < k; j++) {
      long long currentSum = 0;
      for (int i = 0; i < k; i++) currentSum += grid[r + i][c + j];
      if (currentSum != targetSum) return false;
    }

    // 3. 대각선 검사
    long long diag1 = 0, diag2 = 0;
    for (int i = 0; i < k; i++) {
      diag1 += grid[r + i][c + i];          // 주 대각선
      diag2 += grid[r + i][c + k - 1 - i];  // 부 대각선
    }

    if (diag1 != targetSum || diag2 != targetSum) return false;

    return true;
  }

  int largestMagicSquare(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int maximum_k = min(n, m);

    for (int k = maximum_k; k >= 2; k--) {
      for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < m - k + 1; j++) {
          if (isCheck(grid, k, i, j)) return k;
        }
      }
    }

    return 1;
  }
};