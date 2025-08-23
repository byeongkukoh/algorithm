#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Value {
  int val;
  long long multi;
};

map<string, Value> resist;

int main() {
  resist["black"] = {0, 1};
  resist["brown"] = {1, 10};
  resist["red"] = {2, 100};
  resist["orange"] = {3, 1000};
  resist["yellow"] = {4, 10000};
  resist["green"] = {5, 100000};
  resist["blue"] = {6, 1000000};
  resist["violet"] = {7, 10000000};
  resist["grey"] = {8, 100000000};
  resist["white"] = {9, 1000000000};

  long long result = 0;
  for (int i = 0; i < 3; i++) {
    string str;
    cin >> str;

    if (i == 0 || i == 1) {
      result = result * 10 + resist[str].val;
    } else {
      result *= resist[str].multi;
    }
  }

  cout << result;

  return 0;
}