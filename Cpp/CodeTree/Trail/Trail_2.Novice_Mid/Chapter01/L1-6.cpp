#include <iostream>

using namespace std;

void func(int n, int m) {
  int k;
  if (n > m)
    k = m;
  else
    k = n;

  int result = 1;
  for (int i = 1; i <= k; i++) {
    if (n % i == 0 && m % i == 0) {
      result = i;
    }
  }

  cout << result;

  return;
}

int main() {
  int n, m;
  cin >> n >> m;

  func(n, m);
  return 0;
}