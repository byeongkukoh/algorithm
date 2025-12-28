#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, bool> ingredient;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    ingredient.emplace(temp, false);
  }

  for (int i = 0; i < n - 1; i++) {
    string temp;
    cin >> temp;

    ingredient[temp] = true;
  }

  for (auto iter = ingredient.begin(); iter != ingredient.end(); iter++) {
    if (iter->second) continue;

    cout << iter->first;
  }

  return 0;
}