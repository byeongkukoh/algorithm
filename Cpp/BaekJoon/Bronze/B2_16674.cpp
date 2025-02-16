#include <iostream>
#include <string>

using namespace std;

int main() {
  string N;
  cin >> N;

  int cnt_2 = 0;
  int cnt_1 = 0;
  int cnt_0 = 0;
  int cnt_8 = 0;

  int check = true;

  for (int i = 0; i < N.length(); i++) {
    if (N[i] == '2')
      cnt_2++;
    else if (N[i] == '0')
      cnt_0++;
    else if (N[i] == '1')
      cnt_1++;
    else if (N[i] == '8')
      cnt_8++;
    else
      check = false;
  }

  if (!check)
    cout << 0;
  else {
    if (cnt_0 > 0 || cnt_1 > 0 || cnt_2 > 0 || cnt_8 > 0) {
      if (cnt_0 > 0 && cnt_1 > 0 && cnt_2 > 0 && cnt_8 > 0) {
        if (cnt_0 == cnt_1 && cnt_1 == cnt_2 && cnt_2 == cnt_8) {
          cout << 8;
        } else {
          cout << 2;
        }
      } else {
        cout << 1;
      }
    }
  }

  return 0;
}