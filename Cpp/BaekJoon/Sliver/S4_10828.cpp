#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> vect;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    if (str == "push") {
      int num;
      cin >> num;
      vect.push_back(num);
    } else if (str == "pop") {
      if (vect.empty()) {
        cout << -1 << "\n";
      } else {
        cout << vect.back() << "\n";
        vect.pop_back();
      }
    } else if (str == "size") {
      cout << vect.size() << "\n";
    } else if (str == "empty") {
      if (vect.empty()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else if (str == "top") {
      if (vect.empty()) {
        cout << -1 << "\n";
      } else {
        cout << vect.back() << "\n";
      }
    }
  }
  return 0;
}