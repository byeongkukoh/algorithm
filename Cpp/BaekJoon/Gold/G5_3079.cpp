#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> timeList;

bool check(long long timeVal) {
  long long person = 0;

  for (int i = 0; i < N; i++) {
    person += timeVal / timeList[i];

    if (person >= M) return true;
  }

  return false;
}

int main() {
  cin >> N >> M;

  timeList.resize(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> timeList[i];
  }

  sort(timeList.begin(), timeList.end());

  long long lo = 1;
  long long hi = timeList[N - 1] * M;

  long long ans = 0;

  while (lo <= hi) {
    long long mid = (lo + hi) / 2;

    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans;

  return 0;
}