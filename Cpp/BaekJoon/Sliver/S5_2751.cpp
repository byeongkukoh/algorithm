#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> nums;

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;

    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  for (int i = 0; i < N; i++) {
    cout << nums[i] << "\n";
  }

  return 0;
}