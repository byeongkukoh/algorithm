#include <iostream>

using namespace std;

int facto(int n) {
  int res = 1;

  if (n == 0 || n == 1) {
    return res;
  } else {
    for (int i = 1; i <= n; i++) {
      res *= i;
    }
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;

  int facto1 = 1, facto2 = 1, facto3 = 1;

  int res = facto(n) / (facto(k) * facto(n - k));

  cout << res;

  return 0;
}