#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    char ans[80];
    cin >> ans;

    int res = 0, score = 1;

    for (int i = 0; ans[i]; i++) {
      if (ans[i] == 'O') {
        res += score;
        score++;
      } else {
        score = 1;
      }
    }

    cout << res << "\n";
  }

  return 0;
}