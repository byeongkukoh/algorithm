#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vect;

int sum(int floor, int ho) {
  int res = 0;

  for (int i = 0; i <= ho; i++) {
    res += vect[floor][i];
  }
  return res;
}

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    vect.clear();

    int k, n;
    cin >> k >> n;  // k = 층 / n = 호

    vect.resize(k + 1);

    for (int i = 0; i <= n; i++) {
      vect[0].push_back(i);
    }

    for (int i = 1; i <= k; i++) {
      for (int j = 0; j <= n; j++) {
        vect[i].push_back(sum(i - 1, j));
      }
    }

    cout << vect[k][n] << "\n";
  }

  return 0;
}