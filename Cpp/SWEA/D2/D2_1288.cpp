#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    long long n;
    cin >> n;

    set<char> dec;

    int value = n;
    int idx = 1;
    while (1) {
      string temp = to_string(value);

      for (int i = 0; i < temp.length(); i++) {
        dec.insert(temp[i]);
      }

      if (dec.size() == 10) break;

      idx++;
      value = n * idx;
    }

    cout << "#" << t + 1 << " " << value << "\n";
  }

  return 0;
}