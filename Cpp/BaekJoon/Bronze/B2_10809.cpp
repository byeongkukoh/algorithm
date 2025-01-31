#include <iostream>

using namespace std;

int main() {
  char s[101];
  cin >> s;

  int dat[26] = {};  // 0 = a & 25 = z
  for (int i = 0; i < 26; i++) {
    dat[i] = -1;
  }

  for (int i = 0; s[i]; i++) {
    if (dat[s[i] - 'a'] == -1) {
      dat[s[i] - 'a'] = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << dat[i] << " ";
  }

  return 0;
}