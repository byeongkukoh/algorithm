#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums;
  int dat[10000] = {0};
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    sum += temp;
    nums.push_back(temp);
    dat[temp + 4000]++;
  }

  sort(nums.begin(), nums.end());

  // 산술평균 출력 (소수점 첫째자리에서 반올림)
  int res = round(double(sum) / n);
  if (res == 0) res = 0;
  cout << res << "\n";

  // 중앙값
  cout << nums[n / 2] << "\n";

  // 최빈값
  int mode = 0;
  int mode_cnt = 0;
  for (int i = 0; i < 10000; i++) {
    if (dat[i] > dat[mode]) {
      mode = i;
      mode_cnt = 1;
    } else if (dat[i] > 0 && dat[i] == dat[mode]) {
      mode_cnt++;
      if (mode_cnt <= 2) mode = i;
    }
  }

  cout << mode - 4000 << "\n";

  // 범위 (최댓값 - 최솟값)
  cout << nums[n - 1] - nums[0];

  return 0;
}