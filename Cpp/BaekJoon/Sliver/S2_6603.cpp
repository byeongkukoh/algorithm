#include <iostream>
#include <vector>

using namespace std;

void backtracking(int k, vector<int>& nums, vector<int>& path, int now,
                  int idx) {
  if (now == 6) {
    for (int i = 0; i < 6; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  for (int i = idx; i < nums.size(); i++) {
    path.push_back(nums[i]);

    backtracking(k, nums, path, now + 1, i + 1);

    path.pop_back();
  }

  return;
}

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) break;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<int> path;
    backtracking(n, nums, path, 0, 0);

    cout << "\n";
  }

  return 0;
}