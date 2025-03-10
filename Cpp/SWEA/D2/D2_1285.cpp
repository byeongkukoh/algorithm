#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

struct Que {
  int dist;

  bool operator<(Que right) const {
    if (abs(dist) > abs(right.dist)) return true;
    if (abs(dist) < abs(right.dist)) return false;

    return false;
  }
};

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    priority_queue<Que> dist;

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;

      dist.push({temp});
    }

    Que mini = dist.top();
    int cnt = 0;

    while (!dist.empty()) {
      Que now = dist.top();
      dist.pop();

      if (abs(now.dist) == abs(mini.dist)) {
        cnt++;
      }

      if (abs(now.dist) > abs(mini.dist)) break;
    }

    cout << "#" << t + 1 << " " << abs(mini.dist) << " " << cnt << "\n";
  }

  return 0;
}