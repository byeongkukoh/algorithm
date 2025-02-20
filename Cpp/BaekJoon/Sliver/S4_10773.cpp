#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums;
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int input;
    cin >> input;

    if (input == 0) {
      nums.pop_back();
    } else {
      nums.push_back(input);
    }
  }

  int sum = 0;

  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }

  cout << sum;

  return 0;
}