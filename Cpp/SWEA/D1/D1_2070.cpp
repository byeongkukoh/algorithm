#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int a, b;
    cin >> a >> b;

    if (a > b) {
      cout << "#" << t << " " << ">" << "\n";
    } else if (a < b) {
      cout << "#" << t << " " << "<" << "\n";
    } else {
      cout << "#" << t << " " << "=" << "\n";
    }
  }

  return 0;
}