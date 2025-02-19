#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int A, B;
  cin >> A >> B;

  int cnt = 0;

  cnt += A / 2;
  cnt += B;

  if (cnt > n) {
    cnt = n;
  }

  cout << cnt;

  return 0;
}