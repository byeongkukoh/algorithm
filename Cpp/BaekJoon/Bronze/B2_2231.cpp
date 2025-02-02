#include <iostream>

using namespace std;

// 분해합 계산
int divsum(int num) {
  int sum = num;
  while (num > 10) {
    sum += num % 10;
    num /= 10;
  }
  sum += num;

  return sum;
}

int main() {
  int n, ans;
  cin >> n;

  bool check = false;

  for (int i = 1; i < n; i++) {
    int res = divsum(i);
    // cout << res << "\n";
    if (res == n) {
      ans = i;
      check = true;
      break;
    }
  }

  if (check) {
    cout << ans;
  } else {
    cout << 0;
  }

  return 0;
}