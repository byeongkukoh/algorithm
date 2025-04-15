#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> rope;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    rope.push_back(temp);
  }

  sort(rope.begin(), rope.end());

  int max_value = 0;
  int num = 1;
  for (int i = rope.size() - 1; i >= 0; i--) {
    int temp = rope[i] * num;
    num++;
    if (max_value > temp) {
      continue;
    }

    max_value = temp;
  }

  cout << max_value;

  return 0;
}