#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int coins[10] = {0};

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  sort(coins, coins + n);

  int cnt = 0;
  int idx = n - 1;
  while (k != 0) {
    cnt = cnt + k / coins[idx];
    k = k % coins[idx];

    idx--;
  }

  cout << cnt;

  return 0;
}