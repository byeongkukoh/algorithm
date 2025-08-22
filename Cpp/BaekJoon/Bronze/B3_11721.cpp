#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  int cnt = 0;
  for (int i = 0; i < str.length(); i++) {
    if (cnt == 10) {
      cout << "\n";
      cnt = 0;
    }

    cout << str[i];
    cnt++;
  }

  return 0;
}