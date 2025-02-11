#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int arr[10];
    for (int i = 0; i < 10; i++) {
      cin >> arr[i];
    }

    int res = 0;
    for (int i = 0; i < 10; i++) {
      if (arr[i] % 2 == 1) {
        res += arr[i];
      }
    }

    cout << "#" << t << " " << res << "\n";
  }
}