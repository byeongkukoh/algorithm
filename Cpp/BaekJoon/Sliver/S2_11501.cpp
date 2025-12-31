#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    vector<int> price;

    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;

      price.push_back(p);
    }

    int max_price = 0;
    long long result = 0;

    for (int i = n - 1; i >= 0; i--) {
      if (max_price < price[i]) {
        max_price = price[i];
      } else {
        result += (max_price - price[i]);
      }
    }

    cout << result << "\n";
  }

  return 0;
}