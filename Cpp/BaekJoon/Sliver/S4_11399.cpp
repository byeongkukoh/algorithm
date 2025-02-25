#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> time;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    time.push_back(temp);
  }

  sort(time.begin(), time.end());

  vector<int> time_sum;
  for (int i = 0; i < n; i++) {
    int temp;
    if (i == 0)
      temp = time[i];
    else {
      temp = time_sum[i - 1] + time[i];
    }

    time_sum.push_back(temp);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = res + time_sum[i];
  }

  cout << res;

  return 0;
}