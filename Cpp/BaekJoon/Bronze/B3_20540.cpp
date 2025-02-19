#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  if (str[0] == 'E') {
    cout << "I";
  } else if (str[0] == 'I') {
    cout << "E";
  }

  if (str[1] == 'S') {
    cout << "N";
  } else if (str[1] == 'N') {
    cout << "S";
  }

  if (str[2] == 'T') {
    cout << "F";
  } else if (str[2] == 'F') {
    cout << "T";
  }

  if (str[3] == 'J') {
    cout << "P";
  } else if (str[3] == 'P') {
    cout << "J";
  }

  return 0;
}