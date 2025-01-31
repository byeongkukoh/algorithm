#include <iostream>

using namespace std;

int check(int music[8]) {
  bool flag = false;
  int cnt = 0;

  for (int i = 0; i < 8; i++) {
    if (music[i] != i + 1) {
      break;
    }
    cnt++;
  }

  if (cnt == 8) {
    return 1;
  } else {
    cnt = 0;
  }

  for (int i = 0; i < 8; i++) {
    if (music[i] != 8 - i) {
      break;
    }
    cnt++;
  }

  if (cnt == 8) {
    return 2;
  } else {
    return 3;
  }
}

int main() {
  int music[8];
  for (int i = 0; i < 8; i++) {
    cin >> music[i];
  }

  int res = check(music);

  if (res == 1) {
    cout << "ascending";
  } else if (res == 2) {
    cout << "descending";
  } else {
    cout << "mixed";
  }

  return 0;
}