#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  queue<int> nums;

  for (int i = 1; i <= n; i++) {
    nums.push(i);
  }

  while (nums.size() > 1) {
    nums.pop();
    nums.push(nums.front());
    nums.pop();
  }

  cout << nums.front();

  return 0;
}