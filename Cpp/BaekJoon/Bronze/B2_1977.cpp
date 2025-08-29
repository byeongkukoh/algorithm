#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int M, N;
  cin >> M >> N;

  int numSum = 0;
  int minNum = -1;

  int i = sqrt(M);
  for (i; i * i <= N; i++) {
    if ((i * i >= M) && (i * i <= N)) {
      numSum += i * i;

      if (minNum == -1) minNum = i * i;
    }
  }

  if (minNum == -1) {
    cout << -1 << "\n";
    return 0;
  } else {
    cout << numSum << "\n";
    cout << minNum << "\n";
    return 0;
  }
}