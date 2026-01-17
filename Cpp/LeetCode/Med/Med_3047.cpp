class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    long long area = 0;

    for (int i = 0; i < bottomLeft.size(); i++) {
      for (int j = i + 1; j < bottomLeft.size(); j++) {
        int width = min(topRight[i][0], topRight[j][0]) -
                    max(bottomLeft[i][0], bottomLeft[j][0]);

        int height = min(topRight[i][1], topRight[j][1]) -
                     max(bottomLeft[i][1], bottomLeft[j][1]);

        if (width > 0 && height > 0) {
          int temp = min(width, height);

          area = max(area, 1LL * temp * temp);
        }
      }
    }

    return area;
  }
};