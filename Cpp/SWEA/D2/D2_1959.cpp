#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int n, m;
    cin >> n >> m;

    vector<int> A;
    vector<int> B;

    A.resize(n, 0);
    B.resize(m, 0);

    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> B[i];
    }

    int max_res = 0;
    int start_idx = 0;

    if (n <= m) {
      while (start_idx + n <= m) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
          temp += A[i] * B[i + start_idx];
        }

        max_res = max(max_res, temp);

        start_idx++;
      }
    } else {
      while (start_idx + m <= n) {
        int temp = 0;
        for (int i = 0; i < m; i++) {
          temp += A[i + start_idx] * B[i];
        }

        max_res = max(max_res, temp);

        start_idx++;
      }
    }

    cout << "#" << t << " " << max_res << "\n";
  }

  return 0;
}