#include <iostream>

using namespace std;

// 최대공약수 - 유클리드 호제법
int gcd(int a, int b) {
  if (b > a) {
    int temp = a;
    a = b;
    b = temp;
  }

  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

// 최소공배수
int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int main() {
  int a, b;
  cin >> a >> b;

  cout << gcd(a, b) << "\n";
  cout << lcm(a, b);

  return 0;
}