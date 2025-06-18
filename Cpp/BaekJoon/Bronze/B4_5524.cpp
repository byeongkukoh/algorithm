#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;

    for (int j = 0; j < name.size(); j++) {
      if (name[j] >= 'A' && name[j] <= 'Z') {
        cout << char(name[j] + 32);
      } else {
        cout << name[j];
      }
    }

    cout << "\n";
  }

  return 0;
}