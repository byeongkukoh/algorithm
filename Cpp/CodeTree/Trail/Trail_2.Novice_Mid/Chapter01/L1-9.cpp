#include <iostream>

using namespace std;

void func(int n, int m) {
  for (int i = n; i <= n * m; i++) {
    if (i % n == 0 && i % m == 0) {
      cout << i;

      return;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  if (n < m) {
    func(n, m);
  } else {
    func(m, n);
  }

  return 0;
}