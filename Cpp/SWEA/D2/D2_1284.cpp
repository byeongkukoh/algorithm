#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int p, q, r, s, w;
    cin >> p >> q >> r >> s >> w;

    int A, B;

    A = p * w;

    if (w < r) {
      B = q;
    } else {
      B = q + (w - r) * s;
    }

    cout << "#" << t + 1 << " " << min(A, B) << "\n";
  }

  return 0;
}