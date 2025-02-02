#include <iostream>
using namespace std;

long long mod_pow(int i, int r, int m) {
  long long res = 1;

  for (int k = 0; k < i; k++) {
    res = res * r % m;
  }

  return res % m;
}

int main() {
  int n;
  cin >> n;

  char str[51];
  cin >> str;

  int r = 31, M = 1234567891;

  long long ans = 0;
  for (int i = 0; str[i]; i++) {
    ans += ((str[i] - 'a') + 1) * mod_pow(i, r, M) % M;
  }

  ans %= M;

  cout << ans;
  return 0;
}