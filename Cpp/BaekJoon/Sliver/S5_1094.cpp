#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  bitset<7> b(n);

  cout << b.count();

  return 0;
}