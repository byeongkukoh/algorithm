#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  while (1) {
    string str;
    getline(cin, str);

    if (str == ".") break;

    vector<char> s;
    bool check = true;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '(' || str[i] == '[') {
        s.push_back(str[i]);
      } else if (str[i] == ')') {
        if (!s.empty() && s[s.size() - 1] == '(') {
          s.pop_back();
        } else {
          check = false;
          break;
        }
      } else if (str[i] == ']') {
        if (!s.empty() && s[s.size() - 1] == '[') {
          s.pop_back();
        } else {
          check = false;
          break;
        }
      }
    }

    if (check && s.empty()) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}