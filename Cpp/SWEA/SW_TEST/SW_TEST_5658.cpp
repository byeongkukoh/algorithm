#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<string> path;

    for (int i = 0; i < N / 4; i++) {
      int idx = 0;
      while (idx < str.length()) {
        string temp = str.substr(idx, N / 4);
        bool isExist = false;
        for (int i = 0; i < path.size(); i++) {
          if (path[i] == temp) {
            isExist = true;
            break;
          }
        }
        if (!isExist) {
          path.push_back(temp);
        }
        idx += N / 4;
      }
      char temp = str[str.length() - 1];
      str.pop_back();
      str = temp + str;
    }

    sort(path.begin(), path.end(), greater<>());

    string pass_str = path[K - 1];
    int password = 0;

    for (int i = 0; i < pass_str.length(); i++) {
      if (pass_str[i] >= 'A' && pass_str[i] <= 'F') {
        password +=
            (int(pass_str[i] - 'A') + 10) * pow(16, pass_str.length() - 1 - i);
      } else {
        password +=
            (int(pass_str[i] - '1') + 1) * pow(16, pass_str.length() - 1 - i);
      }
    }

    cout << "#" << t + 1 << " " << password << "\n";
  }

  return 0;
}