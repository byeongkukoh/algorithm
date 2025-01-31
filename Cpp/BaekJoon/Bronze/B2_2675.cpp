#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int r;
    cin >> r;

    char str[21];
    cin >> str;

    for (int i = 0; str[i]; i++) {
      for (int j = 0; j < r; j++) {
        cout << str[i];
      }
    }

    cout << "\n";
  }

  return 0;
}