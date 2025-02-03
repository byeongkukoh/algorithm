#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, dat[10001] = {0};
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    dat[a]++;
  }

  for (int i = 0; i < 10001; i++) {
    while (dat[i] > 0) {
      cout << i << "\n";
      dat[i]--;
    }
  }

  return 0;
}