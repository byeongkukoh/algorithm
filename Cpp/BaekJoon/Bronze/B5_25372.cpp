#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string pw;
    cin >> pw;

    if (pw.length() >= 6 && pw.length() <= 9) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}