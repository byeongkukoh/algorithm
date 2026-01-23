#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test_case;
  cin >> test_case;

  vector<vector<long long>> nums;
  nums.assign(65, vector<long long>(10, 1));

  for (int i = 2; i < 65; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j; k < 10; k++) {
        nums[i][j] += nums[i - 1][k];
      }
    }
  }

  for (int t = 0; t < test_case; t++) {
    long long result = 0;

    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
      result += nums[n][i];
    }

    cout << result + 1 << "\n";
  }

  return 0;
}