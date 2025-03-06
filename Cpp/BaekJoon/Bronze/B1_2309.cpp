#include <algorithm>
#include <iostream>

using namespace std;

int nums[9];
int path[7];
int visited[9];

int result[7];

void func(int now) {
  if (now == 7) {
    int sum = 0;

    for (int i = 0; i < 7; i++) {
      sum += path[i];
    }

    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        result[i] = path[i];
      }
    }
    return;
  }

  for (int i = 0; i < 9; i++) {
    if (visited[i] == 1) continue;
    if (now > 0 && path[now - 1] > nums[i]) continue;

    path[now] = nums[i];
    visited[i] = 1;

    func(now + 1);

    path[now] = 0;
    visited[i] = 0;
  }
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> nums[i];
  }

  sort(nums, nums + 9);

  func(0);

  sort(result, result + 7);

  for (int i = 0; i < 7; i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
