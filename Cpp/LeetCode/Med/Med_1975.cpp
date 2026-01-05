#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int cntMinus = 0;

    int minValue = INT_MAX;
    long long result = 0;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] < 0) cntMinus++;

        result += abs(matrix[i][j]);

        minValue = min(minValue, abs(matrix[i][j]));
      }
    }

    if (cntMinus % 2 == 0) {
      return result;
    } else {
      return result - (minValue * 2);
    }
  }
};