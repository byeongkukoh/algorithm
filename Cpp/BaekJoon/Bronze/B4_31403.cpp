#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << a + b - c << "\n";

  int temp = b, bLength = 0;

  while (temp > 0) {
    temp = temp / 10;
    bLength++;
  }

  cout << a * int(pow(10, bLength)) + b - c;

  return 0;
}

// cmath의 pow 함수는 기본적으로 double 형을 반환함
// --> 큰 문제는 없지만 알고리즘 문제에서 오류가 발생하지 않으려면
//     정수형으로 변환이 필요
