#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<int> path;
vector<bool> visited;

void func(int now) {
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      if (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) continue;
      if (now > 0 && path[now - 1] > nums[i]) continue;

      path.push_back(nums[i]);
      visited[i] = true;

      func(now + 1);

      path.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  visited.resize(N, false);

  func(0);

  return 0;
}