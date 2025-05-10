#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a, b;
  cin >> a >> b;

  bitset<11> bita;

  if (n >= a + b) {
    for (int i = n - 1; i >= n - a - b; i--) {
      bita |= (1 << i);
    }
  } else {
    int temp = (a + b) - n;

    for (int i = 0; i < n; i++) {
      bita |= (1 << i);
    }

    for (int i = 0; i < temp; i++) {
      bita ^= (1 << i);
    }
  }

  cout << bita.to_ullong();

  return 0;
}