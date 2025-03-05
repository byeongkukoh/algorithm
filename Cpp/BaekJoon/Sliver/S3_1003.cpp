#include <iostream>
#include <vector>

using namespace std;

struct Count {
  int zero;
  int one;
};

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    vector<Count> cnt;

    cnt.push_back({1, 0});
    cnt.push_back({0, 1});

    if (n == 0) {
      cout << cnt[0].zero << " " << cnt[0].one << "\n";
    } else if (n == 1) {
      cout << cnt[1].zero << " " << cnt[1].one << "\n";
    } else {
      for (int i = 2; i <= n; i++) {
        cnt.push_back({cnt[i - 2].zero + cnt[i - 1].zero,
                       cnt[i - 2].one + cnt[i - 1].one});
      }

      cout << cnt[n].zero << " " << cnt[n].one << "\n";
    }
  }

  return 0;
}

// int zeroCnt;
// int oneCnt;

// int fibonacci(int n) {
//   if (n == 0) {
//     zeroCnt++;
//     return 0;
//   } else if (n == 1) {
//     oneCnt++;
//     return 1;
//   } else {
//     return fibonacci(n - 1) + fibonacci(n - 2);
//   }
// }

// int main() {
//   int test;
//   cin >> test;

//   for (int t = 0; t < test; t++) {
//     zeroCnt = 0;
//     oneCnt = 0;

//     int n;
//     cin >> n;

//     fibonacci(n);

//     cout << zeroCnt << " " << oneCnt << "\n";
//   }

// return 0;
// }