#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Time {
  int t;
  int s;
};

bool cmp(Time left, Time right) {
  if (left.s > right.s) return true;
  if (left.s < right.s) return false;

  if (left.t > right.t) return true;
  if (left.t < right.t) return false;

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Time> work;

  for (int i = 0; i < n; i++) {
    int t, s;
    cin >> t >> s;

    work.push_back({t, s});
  }

  sort(work.begin(), work.end(), cmp);

  int start_time = work[0].s;

  for (int i = 0; i < n; i++) {
    start_time = min(start_time, work[i].s);

    start_time -= work[i].t;

    if (start_time < 0) {
      cout << -1 << "\n";
      return 0;
    }
  }

  cout << start_time << "\n";

  return 0;
}