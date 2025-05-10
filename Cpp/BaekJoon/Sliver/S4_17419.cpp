#include <bitset>
#include <iostream>

using namespace std;

bitset<2000000> bit;

int main() {
  int n;
  cin >> n;

  cin >> bit;

  cout << bit.count();

  return 0;
}