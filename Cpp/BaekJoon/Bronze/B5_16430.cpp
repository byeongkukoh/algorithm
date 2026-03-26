#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int main() {
  int A, B;
  cin >> A >> B;

  int P = B - A;
  int Q = B;

  int g = gcd(P, Q);

  if (g != 1) {
    P = P / g;
    Q = Q / g;
  }

  cout << P << " " << Q;

  return 0;
}