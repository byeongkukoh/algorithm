#include <cmath>
#include <iostream>
using namespace std;

bool isPrimeNumber(int number) {
  if (number == 1) {
    return false;
  }

  if (number == 2) {
    return true;
  }

  for (int i = 2; i < sqrt(number) + 1; i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int m, n;
  cin >> m >> n;

  for (int num = m; num <= n; num++) {
    if (isPrimeNumber(num)) {
      cout << num << "\n";
    }
  }

  return 0;
}