#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    long long m;
    cin >> m;

    bitset<64> b(m);

    if (b.count() == 1) {
      for (int t = 0; t < 64; t++) {
        if (b.test(t)) {
          cout << t - 1 << " " << t - 1 << "\n";
          break;
        }
      }
    } else {
      for (int t = 0; t < 64; t++) {
        if (b.test(t)) {
          cout << t << " ";
        }
      }

      cout << "\n";
    }
  }

  return 0;
}