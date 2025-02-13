#include <algorithm>
#include <iostream>

using namespace std;

int N, M;

int nums[20];
int path[20] = {0};
bool used[20] = {false};

void func(int now) {
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;

      path[now] = nums[i];
      used[i] = true;

      func(now + 1);

      path[now] = 0;
      used[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  sort(nums, nums + N);

  func(0);

  return 0;
}