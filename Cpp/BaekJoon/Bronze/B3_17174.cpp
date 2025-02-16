#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int res = 0;

  while (N > 0) {
    res += N;
    N = N / M;
  }

  cout << res;

  return 0;
}