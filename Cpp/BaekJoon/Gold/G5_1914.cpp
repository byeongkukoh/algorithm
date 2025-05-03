#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, int from, int via, int to) {
  if (n == 1) {
    cout << from << " " << to << "\n";
    return;
  }

  hanoi(n - 1, from, to, via);
  cout << from << " " << to << "\n";
  hanoi(n - 1, via, from, to);
}

int main() {
  int n;
  cin >> n;

  string res = to_string(pow(2.0, n));

  int x = res.find(".");
  res = res.substr(0, x);

  res[res.length() - 1] -= 1;

  cout << res << "\n";

  if (n <= 20) {
    hanoi(n, 1, 2, 3);
  }

  return 0;
}