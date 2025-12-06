#include <iostream>
#include <string>

using namespace std;

int main() {
  string arr[10][10];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> arr[i][j];
    }
  }

  // 행 체크
  bool flag = false;
  for (int i = 0; i < 10; i++) {
    string now = arr[i][0];

    for (int j = 1; j < 10; j++) {
      if (now != arr[i][j]) {
        flag = false;
        break;
      }

      flag = true;
    }

    if (flag) break;
  }

  if (flag) {
    cout << 1 << endl;
    return 0;
  }

  // 열 체크
  for (int i = 0; i < 10; i++) {
    string now = arr[0][i];

    for (int j = 1; j < 10; j++) {
      if (now != arr[j][i]) {
        flag = false;
        break;
      }

      flag = true;
    }

    if (flag) break;
  }

  if (flag) {
    cout << 1 << endl;
    return 0;
  }

  cout << 0 << endl;

  return 0;
}