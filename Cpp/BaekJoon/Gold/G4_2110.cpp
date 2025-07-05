#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, c;
vector<int> house;

bool check(int dist) {
  int cnt = 1;
  int last = house[0];

  for (int i = 0; i < n; i++) {
    if (house[i] - last >= dist) {
      cnt++;
      last = house[i];
    }
  }

  return cnt >= c;
}

int main() {
  cin >> n >> c;

  house.resize(n, 0);

  for (int i = 0; i < n; i++) cin >> house[i];

  sort(house.begin(), house.end());

  int lo = 1;
  int hi = house[n - 1] - house[0];

  int dist = 0;

  while (lo <= hi) {
    int mid = (hi + lo) / 2;

    if (check(mid)) {
      dist = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << dist;

  return 0;
}