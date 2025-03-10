#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0, d = 0, e = 0;

    while (n > 1) {
      if (n % 11 == 0) {
        n /= 11;
        e++;
      } else if (n % 7 == 0) {
        n /= 7;
        d++;
      } else if (n % 5 == 0) {
        n /= 5;
        c++;
      } else if (n % 3 == 0) {
        n /= 3;
        b++;
      } else if (n % 2 == 0) {
        n /= 2;
        a++;
      }
    }

    cout << "#" << t + 1 << " " << a << " " << b << " " << c << " " << d << " "
         << e << "\n";
  }
  return 0;
}