#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double a, b, v;
  cin >> a >> b >> v;

  int day = ceil((v - a) / (a - b)) + 1;

  cout << day;

  return 0;
}