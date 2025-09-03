#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> nums(n + 1, vector<int>(n + 1, 0));

  // 입력 + 행별 누적합
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      int temp;
      cin >> temp;

      if (y == 1) {
        nums[x][y] = temp;
      } else {
        nums[x][y] = nums[x][y - 1] + temp;
      }
    }
  }

  // 질의 처리
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int res = 0;

    for (int x = x1; x <= x2; x++) {
      if (y1 > 1) {
        res += nums[x][y2] - nums[x][y1 - 1];
      } else {
        res += nums[x][y2];
      }
    }

    cout << res << "\n";
  }

  return 0;
}
