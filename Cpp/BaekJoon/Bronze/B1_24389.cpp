#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a;
  cin >> a;

  bitset<32> bit1(a);
  bitset<32> bit2((a ^ 0xFFFFFFFF) + 1);

  int cnt = 0;

  string temp1 = bit1.to_string();
  string temp2 = bit2.to_string();

  for (int i = 0; i < 32; i++) {
    if (temp1[i] != temp2[i]) cnt++;
  }

  cout << cnt;

  return 0;
}
