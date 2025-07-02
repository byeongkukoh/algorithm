#include <iostream>
#include <vector>

using namespace std;

int N, r, c;
int result = 0;

void divide(int x, int y, int size) {
  if (size == 1) return;

  int half = size / 2;

  // 제 1 사분면
  if (r < y + half && c < x + half) {
    divide(x, y, half);
  }
  // 제 2 사분면
  else if (r < y + half && c >= x + half) {
    result += half * half;
    divide(x + half, y, half);
  }
  // 제 3 사분면
  else if (r >= y + half && c < x + half) {
    result += half * half * 2;
    divide(x, y + half, half);
  }
  // 제 4 사분면
  else {
    result += half * half * 3;
    divide(x + half, y + half, half);
  }
}

int main() {
  cin >> N >> r >> c;

  int size = 1 << N;

  divide(0, 0, size);

  cout << result;

  return 0;
}