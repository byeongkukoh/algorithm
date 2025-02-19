#include <iostream>

using namespace std;

int main() {
  int k, n, m;
  cin >> k >> n >> m;

  int res = (k * n) - m;

  if (res < 0) {
    res = 0;
  }

  cout << res;
  return 0;
}