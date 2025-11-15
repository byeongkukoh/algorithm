#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> nums;
int oper[4];  // 덧셈, 뺄셈, 곱셈, 나눗셈
vector<int> path;

int min_ans = INT_MAX;
int max_ans = INT_MIN;

void backtracking(int now) {
  if (now == n - 1) {
    int temp = nums[0];

    for (size_t i = 0; i < path.size(); i++) {
      if (path[i] == 0) {
        temp += nums[i + 1];
      } else if (path[i] == 1) {
        temp -= nums[i + 1];
      } else if (path[i] == 2) {
        temp *= nums[i + 1];
      } else {
        temp /= nums[i + 1];
      }
    }

    if (max_ans < temp) max_ans = temp;
    if (min_ans > temp) min_ans = temp;

    return;
  }

  for (int i = 0; i < 4; i++) {
    if (oper[i] == 0) continue;

    path.push_back(i);
    oper[i] -= 1;

    backtracking(now + 1);

    path.pop_back();
    oper[i] += 1;
  }

  return;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    nums.push_back(temp);
  }

  for (int i = 0; i < 4; i++) {
    cin >> oper[i];
  }

  backtracking(0);

  cout << max_ans << endl;
  cout << min_ans << endl;

  return 0;
}