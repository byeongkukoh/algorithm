#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    int dist = 0, vel = 0;
    ;

    for (int i = 0; i < n; i++) {
      int comm, acc;
      cin >> comm;

      if (comm == 0) {
        dist = dist + (vel * 1);
      } else if (comm == 1) {
        cin >> acc;
        vel = vel + acc;
        dist = dist + (vel * 1);
      } else {
        cin >> acc;
        vel = vel - acc;
        if (vel < 0) vel = 0;

        dist = dist + (vel * 1);
      }
    }

    cout << "#" << t + 1 << " " << dist << "\n";
  }
  return 0;
}