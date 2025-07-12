#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  string str;
  cin >> str;

  int cnt = 0, res = 0;

  for (int i = 1; i < m - 1; i++) {
    if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
      cnt++;

      if (cnt == n) {
        res++;
        cnt--;
      }

      i += 1;
    } else {
      cnt = 0;
    }
  }

  cout << res;

  return 0;
}