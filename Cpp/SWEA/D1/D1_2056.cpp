#include <iostream>
#include <string>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    string date;
    cin >> date;

    string year = date.substr(0, 4);
    string month = date.substr(4, 2);
    string day = date.substr(6, 2);

    bool isDate = true;

    if (stoi(month) < 1 || stoi(month) > 12) isDate = false;

    if (stoi(month) == 1 || stoi(month) == 3 || stoi(month) == 5 ||
        stoi(month) == 7 || stoi(month) == 8 || stoi(month) == 10 ||
        stoi(month) == 12) {
      if (stoi(day) < 1 || stoi(day) > 31) isDate = false;
    }

    if (stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 ||
        stoi(month) == 11) {
      if (stoi(day) < 1 || stoi(day) > 30) isDate = false;
    }

    if (stoi(month) == 2) {
      if (stoi(day) < 1 || stoi(day) > 28) isDate = false;
    }

    if (isDate) {
      cout << "#" << t << " " << year << "/" << month << "/" << day << "\n";
    } else {
      cout << "#" << t << " " << -1 << "\n";
    }
  }

  return 0;
}