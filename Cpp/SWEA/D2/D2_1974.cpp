#include <iostream>
#include <set>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int map[9][9];
    bool isRight = true;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin >> map[i][j];
      }
    }

    // 행 / 열 점검
    for (int i = 0; i < 9; i++) {
      set<int> row;
      set<int> col;

      for (int j = 0; j < 9; j++) {
        col.insert(map[i][j]);
        row.insert(map[j][i]);
      }

      if (row.size() != 9) {
        isRight = false;
        break;
      }

      if (col.size() != 9) {
        isRight = false;
        break;
      }
    }

    // 3 x 3 점검
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        set<int> cct;
        for (int row = 0 + i; row < 3 + i; row++) {
          for (int col = 0 + j; col < 3 + j; col++) {
            cct.insert(map[row][col]);
          }
        }

        if (cct.size() != 9) {
          isRight = false;
          break;
        }
      }
    }

    if (isRight) {
      cout << "#" << t + 1 << " " << 1 << "\n";
    } else {
      cout << "#" << t + 1 << " " << 0 << "\n";
    }
  }
  return 0;
}