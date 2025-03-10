#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int money;
    cin >> money;

    cout << "#" << t + 1 << "\n";

    for (int i = 0; i < 8; i++) {
      if (i == 0) {
        cout << money / 50000 << " ";
        money %= 50000;
      } else if (i == 1) {
        cout << money / 10000 << " ";
        money %= 10000;
      } else if (i == 2) {
        cout << money / 5000 << " ";
        money %= 5000;
      } else if (i == 3) {
        cout << money / 1000 << " ";
        money %= 1000;
      } else if (i == 4) {
        cout << money / 500 << " ";
        money %= 500;
      } else if (i == 5) {
        cout << money / 100 << " ";
        money %= 100;
      } else if (i == 6) {
        cout << money / 50 << " ";
        money %= 50;
      } else if (i == 7) {
        cout << money / 10 << " ";
        money %= 10;
      }
    }

    cout << "\n";
  }

  return 0;
}