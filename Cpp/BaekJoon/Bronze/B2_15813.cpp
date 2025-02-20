#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string name;
  cin >> name;

  int score = 0;
  for (int i = 0; i < n; i++) {
    score += int(name[i] - 'A' + 1);
  }

  cout << score;

  return 0;
}