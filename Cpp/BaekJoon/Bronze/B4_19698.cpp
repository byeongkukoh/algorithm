#include <iostream>

using namespace std;

int main() {
  int N, W, H, L;
  cin >> N >> W >> H >> L;

  int width = W / L;
  int height = H / L;

  int pos = width * height;

  if (pos < N)
    cout << pos;
  else
    cout << N;

  return 0;
}