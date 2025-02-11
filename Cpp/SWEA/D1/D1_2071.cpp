#include <cmath>
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

    int sum = 0;
    for (int i = 0; i < 10; i++) {
      sum += arr[i];
    }

    cout << "#" << t << " " << floor((double)sum / 10 + 0.5) << "\n";
  }

  return 0;
}