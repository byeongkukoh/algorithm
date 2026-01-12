class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int minSeconds = 0;

    for (int i = 1; i < points.size(); i++) {
      if (abs(points[i - 1][0] - points[i][0]) >
          abs(points[i - 1][1] - points[i][1])) {
        minSeconds += abs(points[i - 1][0] - points[i][0]);
      } else {
        minSeconds += abs(points[i - 1][1] - points[i][1]);
      }
    }

    return minSeconds;
  }
};