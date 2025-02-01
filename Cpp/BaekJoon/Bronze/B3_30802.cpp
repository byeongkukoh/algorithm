#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  // S M L XL XXL XXXL
  int size[6] = {0};
  for (int i = 0; i < 6; i++) {
    cin >> size[i];
  }

  int t, p;
  cin >> t >> p;

  int shirts = 0;

  for (int i = 0; i < 6; i++) {
    shirts = shirts + (size[i] / t);
    size[i] = size[i] % t;

    if (size[i] > 0) {
      shirts++;
    }
  }

  cout << shirts << "\n";
  cout << n / p << " " << n % p;

  return 0;
}