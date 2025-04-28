#include <iostream>
#include <vector>

using namespace std;

vector<int> vect;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int comm;
    cin >> comm;

    if (comm == 1) {
      int num;
      cin >> num;

      vect.push_back(num);
    } else if (comm == 2) {
      if (vect.size() == 0) {
        cout << -1 << "\n";
      } else {
        cout << vect[vect.size() - 1] << "\n";
        vect.pop_back();
      }
    } else if (comm == 3) {
      cout << vect.size() << "\n";
    } else if (comm == 4) {
      if (vect.empty()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else {
      if (!vect.empty()) {
        cout << vect[vect.size() - 1] << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }

  return 0;
}