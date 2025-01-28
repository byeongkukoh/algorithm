#include <iostream>
using namespace std;

int main() {
  int arr[5] = {0};
  int sum = 0;

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum = sum + (arr[i] * arr[i]);
  }

  cout << sum % 10 << endl;

  return 0;
}