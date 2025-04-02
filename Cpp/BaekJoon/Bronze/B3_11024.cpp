#include <iostream>
#include <string>

using namespace std;

int main() {
  int test;
  cin >> test;

  cin.ignore();

  for (int t = 0; t < test; t++) {
    string str;
    getline(cin, str);

    int res = 0;
    string temp = "";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ' ') {
        res += stoi(temp);
        temp = "";

        continue;
      }

      temp += str[i];
    }

    res += stoi(temp);

    cout << res << "\n";
  }

  return 0;
}