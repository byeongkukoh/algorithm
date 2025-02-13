#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int dat[21] = {0};
  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    string str;
    cin >> str;

    if (str == "all") {
      for (int i = 1; i <= 20; i++) {
        dat[i]++;
      }
      continue;
    } else if (str == "empty") {
      dat[21] = {0};
      continue;
    }

    int num;
    cin >> num;

    if (str == "add") {
      dat[num] = 1;
    } else if (str == "remove") {
      dat[num]--;
    } else if (str == "check") {
      if (dat[num] == 1)
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    } else if (str == "toggle") {
      if (dat[num] == 1)
        dat[num] = 0;
      else
        dat[num] = 1;
    }
  }

  return 0;
}