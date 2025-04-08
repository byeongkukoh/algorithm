#include <iostream>

using namespace std;

void printRect(int n) {
  int now = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << now % 9 + 1 << " ";
      now++;
    }
    cout << "\n";
  }
}

int main() {
  int n;
  cin >> n;

  printRect(n);

  return 0;
}