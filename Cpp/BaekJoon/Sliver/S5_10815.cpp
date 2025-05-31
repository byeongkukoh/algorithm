#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> num;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    num.push_back(temp);
  }

  sort(num.begin(), num.end());

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;

    if (binary_search(num.begin(), num.end(), temp)) {
      cout << 1 << " ";
    } else {
      cout << 0 << " ";
    }
  }

  return 0;
}