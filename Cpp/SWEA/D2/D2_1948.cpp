#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int month1, day1, month2, day2;
    cin >> month1 >> day1 >> month2 >> day2;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int res = 0;
    for (int i = month1 - 1; i < month2; i++) {
      res += days[i];
    }

    res = res - (day1 - 1);
    res = res - (days[month2 - 1] - day2);

    cout << "#" << t + 1 << " " << res << "\n";
  }

  return 0;
}