#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int arr[10];

    for (int i = 0; i < 10; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + 10);

    cout << "#" << t + 1 << " " << arr[9] << "\n";
  }

  return 0;
}