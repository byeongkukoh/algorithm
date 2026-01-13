class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    double high = 0.0;
    double low = 1000000000.0 * 2;

    for (size_t i = 0; i < squares.size(); i++) {
      if (squares[i][1] + squares[i][2] > high)
        high = squares[i][1] + squares[i][2];

      if (squares[i][1] < low) low = squares[i][1];
    }

    int cnt = 0;
    while (cnt < 100) {
      double mid = (low + high) / 2.0;

      double top_area = 0;
      double bottom_area = 0;

      for (size_t i = 0; i < squares.size(); i++) {
        double y = squares[i][1];
        double height = squares[i][2];
        double width = squares[i][2];

        // 사각형 중간에 축이 통과하는 경우
        if (mid >= y && mid <= y + height) {
          top_area += (y + height - mid) * width;
          bottom_area += (mid - y) * width;
        }
        // 사격형이 축 위에 있는 경우
        else if (mid < y) {
          top_area += (height * width);
        }
        // 사각형이 축 아래에 있는 경우
        else {
          bottom_area += (height * width);
        }
      }

      if (top_area > bottom_area) {
        low = mid;
      } else {
        high = mid;
      }

      cnt++;
    }

    return high;
  }
};