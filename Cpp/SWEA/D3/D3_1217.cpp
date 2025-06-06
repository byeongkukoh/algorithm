#include <iostream>

using namespace std;

int result = 1;

void func(int now, int n, int m) {
  if (now == m) {
    return;
  }

  result = result * n;
  func(now + 1, n, m);
}

int main() {
  for (int t = 1; t <= 10; t++) {
    result = 1;

    int test;
    cin >> test;

    int n, m;
    cin >> n >> m;

    func(0, n, m);

    cout << "#" << test << " " << result << "\n";
  }

  return 0;
}