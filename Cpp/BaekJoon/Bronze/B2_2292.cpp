#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int i = 1, sum = 1;
  while (sum < n) {
    i++;
    sum = 3 * i * (i - 1) + 1;
  }

  cout << i;

  return 0;
}