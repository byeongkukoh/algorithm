#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  string temp_result = "";

  bitset<4> temp1(a & 0xF);
  bitset<4> temp2(b & 0xF);
  bitset<4> temp3(c & 0xF);

  temp_result = temp1.to_string() + temp2.to_string() + temp3.to_string();

  bitset<12> result(temp_result);

  string out_result = to_string(result.to_ulong());

  if (out_result.size() != 4) {
    for (int i = 0; i < 4 - out_result.size(); i++) {
      cout << '0';
    }
  }

  cout << out_result;

  return 0;
}