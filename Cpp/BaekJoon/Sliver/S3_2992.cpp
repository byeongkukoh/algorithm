#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string x;
int path[10];
int used[10] = {0};

vector<int> nums;

void func(int now) {
  // 탈출 함수
  if (now == x.length()) {
    string temp;
    for (int i = 0; i < x.length(); i++) {
      temp += to_string(path[i]);
    }
    nums.push_back(stoi(temp));
    return;
  }

  // 재귀
  for (int i = 0; i < x.length(); i++) {
    if (used[i] == 1) continue;

    path[now] = x[i] - 48;
    used[i] = 1;

    func(now + 1);

    path[now] = 0;
    used[i] = 0;
  }
}
int main() {
  cin >> x;

  func(0);

  // for (int i = 0; i < nums.size(); i++) {
  //   cout << nums[i] << " ";
  // }

  sort(nums.begin(), nums.end());

  int min = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > stoi(x)) {
      min = nums[i];
      break;
    }
  }

  if (min == 0)
    cout << 0;
  else
    cout << min;

  return 0;
}