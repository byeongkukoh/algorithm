#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;

      nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    cout << "#" << t + 1 << " ";
    for (int i = 0; i < n; i++) {
      cout << nums[i] << " ";
    }

    cout << "\n";
  }

  return 0;
}