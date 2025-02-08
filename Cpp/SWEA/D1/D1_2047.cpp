#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  string ans_str;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      ans_str += char(str[i] - 32);
    } else {
      ans_str += str[i];
    }
  }

  cout << ans_str;

  return 0;
}