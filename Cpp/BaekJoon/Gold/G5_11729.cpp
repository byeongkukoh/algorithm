#include <iostream>

using namespace std;

void hanoi(int n, int from, int via, int to) {
  if (n == 1) {
    cout << from << " " << to << "\n";
    return;
  }

  hanoi(n - 1, from, to, via);
  cout << from << " " << to << "\n";
  hanoi(n - 1, via, from, to);
}

int main() {
  int n;
  cin >> n;

  cout << (1 << n) - 1 << "\n";

  hanoi(n, 1, 2, 3);

  return 0;
}