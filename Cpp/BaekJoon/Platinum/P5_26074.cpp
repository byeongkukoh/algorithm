#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if ((n == 2 && m == 1) || (n == 1 && m == 2)) {
    cout << "ChongChong";
  } else {
    cout << "GomGom";
  }

  return 0;
}