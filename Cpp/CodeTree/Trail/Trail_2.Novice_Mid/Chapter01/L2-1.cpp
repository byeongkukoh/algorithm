#include <iostream>

using namespace std;

int func(int n) {
  int total = 0;

  for (int i = 1; i <= n; i++) {
    total += i;
  }

  return total / 10;
}

int main() {
  int n;
  cin >> n;

  int result = func(n);

  cout << result;

  return 0;
}