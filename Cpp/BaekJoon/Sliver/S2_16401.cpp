#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> snack;

bool check(int leng) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (snack[i] >= leng) {
      cnt += snack[i] / leng;
    }
  }

  return cnt >= m;
}

int main() {
  cin >> m >> n;

  snack.resize(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> snack[i];
  }

  sort(snack.begin(), snack.end());

  int lo = 1;
  int hi = snack[n - 1];

  int leng = 0;

  while (lo <= hi) {
    int mid = (hi + lo) / 2;

    if (check(mid)) {
      lo = mid + 1;
      leng = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << leng;

  return 0;
}