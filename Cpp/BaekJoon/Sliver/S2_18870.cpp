#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> nums;
  vector<int> unsortNums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    nums.push_back(temp);
    unsortNums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  map<int, int> numCnt;  // key: number & value: count
  numCnt[nums[0]] = 0;

  for (int i = 1; i < n; i++) {
    if (nums[i - 1] == nums[i]) continue;

    numCnt[nums[i]] = numCnt[nums[i - 1]] + 1;
  }

  for (int i = 0; i < n; i++) {
    cout << numCnt[unsortNums[i]] << " ";
  }

  return 0;
}