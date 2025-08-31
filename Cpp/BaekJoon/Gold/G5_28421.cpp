#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers;
  map<int, int> cntNumbers;
  int cntZero = 0;

  int N, Q;
  cin >> N >> Q;

  numbers.resize(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    int temp;
    cin >> temp;

    numbers[i] = temp;
    cntNumbers[temp] += 1;

    if (temp == 0) cntZero++;
  }

  for (int query = 0; query < Q; query++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      int x;
      cin >> x;

      bool check = false;

      if (N == 1) {
        cout << 0 << "\n";
        continue;
      }

      if (x == 0) {
        if (cntZero > 0) {
          cout << 1 << "\n";
        } else {
          cout << 0 << "\n";
        }

        continue;
      }

      for (int i = 1; i <= sqrt(x); i++) {
        if (x % i != 0) continue;

        map<int, int>::iterator it = cntNumbers.find(i);
        // i의 값이 존재하면,
        if (it != cntNumbers.end()) {
          // 현재 i 값이 없으면, 다음으로 진행
          if (cntNumbers[i] <= 0) continue;

          // 현재 i 값이 있으면
          int j = x / i;
          map<int, int>::iterator jt = cntNumbers.find(j);

          // j의 값이 존재하면,
          if (jt != cntNumbers.end()) {
            if (cntNumbers[j] <= 0) {
              continue;
            } else if (j == i) {
              if (cntNumbers[j] >= 2) {
                check = true;
                break;
              } else {
                continue;
              }
            } else {
              check = true;
              break;
            }
          }
        }
      }

      if (check) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else {
      int i;
      cin >> i;

      int temp = numbers[i];
      numbers[i] = 0;

      cntZero++;
      cntNumbers[temp] -= 1;
    }
  }

  return 0;
}