#include <iostream>
#include <vector>

using namespace std;

int cnt;

void func(int sum, int n) {
  if (sum >= n) {
    if (sum > n) {
      return;
    }

    if (sum == n) {
      cnt++;
      return;
    }
  }

  for (int i = 1; i <= 3; i++) {
    func(sum + i, n);
  }
}

int main() {
  int test;
  cin >> test;

  for (int i = 0; i < test; i++) {
    cnt = 0;

    int n;
    cin >> n;

    func(0, n);

    cout << cnt << "\n";
  }

  return 0;
}