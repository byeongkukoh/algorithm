#include <iostream>
#include <string>

using namespace std;

int main() {
  while (true) {
    string str;
    cin >> str;

    if (str == "end") break;

    if (str == "animal") {
      cout << "Panthera tigris" << endl;
    } else if (str == "flower") {
      cout << "Forsythia koreana" << endl;
    } else if (str == "tree") {
      cout << "Pinus densiflora" << endl;
    }
  }

  return 0;
}