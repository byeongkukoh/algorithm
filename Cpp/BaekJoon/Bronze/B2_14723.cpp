#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      int A = i - j + 1;
      int B = j;
      cnt++;

      if (cnt == N) {
        cout << A << " " << B;
        return 0;
      }
    }
  }

  return 0;
}
