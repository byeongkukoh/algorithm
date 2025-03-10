#include <iostream>
#include <string>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    string ans = "";

    for (int i = 0; i < n; i++) {
      string temp;
      int k;
      cin >> temp >> k;

      for (int j = 0; j < k; j++) {
        ans += temp;
      }
    }

    cout << "#" << t + 1 << "\n";

    int cnt = 0;
    for (int i = 0; i < ans.length(); i++) {
      cout << ans[i];
      cnt++;

      if (cnt == 10) {
        cout << "\n";
        cnt = 0;
      }
    }

    cout << "\n";
  }

  return 0;
}