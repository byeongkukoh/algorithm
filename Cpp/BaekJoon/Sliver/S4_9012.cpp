#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int _ = 0; _ < T; _++) {
    string str;
    cin >> str;

    vector<char> s;
    bool check = true;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '(') {
        s.push_back(str[i]);
      } else {
        if (!s.empty() && s[s.size() - 1] == '(') {
          s.pop_back();
        } else {
          check = false;
          break;
        }
      }
    }

    if (check && s.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}