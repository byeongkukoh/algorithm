#include <bitset>
#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;

  bitset<64> bit(n);

  long long res = 0;
  int cnt = 0;
  for (int i = 0; i < 64; i++) {
    if (bit[i] == 1) {
      long long temp = 1;
      if (cnt != 0) {
        for (int j = 0; j < cnt; j++) {
          temp *= 3;
        }
      }

      res += temp;
    }
    cnt++;
  }

  cout << res << "\n";

  return 0;
}