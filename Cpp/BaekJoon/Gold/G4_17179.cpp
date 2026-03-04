#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, L;

vector<int> cutting_point;

bool check(int mid, int cnt) {
  int pieces = 0;

  int now = 0;

  for (int i = 0; i < M; i++) {
    if (cutting_point[i] - now >= mid) {
      pieces++;
      now = cutting_point[i];
    }
  }

  if (L - now < mid) pieces--;

  return pieces >= cnt;
}

int main() {
  cin >> N >> M >> L;

  for (int i = 0; i < M; i++) {
    int temp;
    cin >> temp;

    cutting_point.push_back(temp);
  }

  sort(cutting_point.begin(), cutting_point.end());

  for (int i = 0; i < N; i++) {
    int cnt;
    cin >> cnt;

    int lo = 1;
    int hi = L;

    int result = 0;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;

      if (check(mid, cnt)) {
        result = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    cout << result << "\n";
  }

  return 0;
}