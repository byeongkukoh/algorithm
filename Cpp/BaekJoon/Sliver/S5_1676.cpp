#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = 0;
  for (int i = 1; i < 4; i++) {
    cnt += N / int(pow(5, i));
  }

  cout << cnt;

  return 0;
}