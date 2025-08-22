#include <iostream>

using namespace std;

int val[9][9];

int main() {
  int max_val = -1;
  int row = -1;
  int col = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> val[i][j];

      if (val[i][j] > max_val) {
        max_val = val[i][j];
        row = i;
        col = j;
      }
    }
  }

  cout << max_val << endl;
  cout << row + 1 << " " << col + 1;

  return 0;
}