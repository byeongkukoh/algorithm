#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int number_round(double number) {
  if (number + 0.5 >= (int)number + 1) {
    return number + 1;
  } else {
    return number;
  }
}

int main() {
  vector<int> scores;
  int n;
  cin >> n;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    scores.push_back(temp);
  }

  sort(scores.begin(), scores.end());

  double exc = double(scores.size()) * 0.15;

  exc = number_round(exc);

  int sum = 0;
  for (int i = exc; i < scores.size() - exc; i++) {
    sum += scores[i];
  }

  cout << number_round(double(sum) / (scores.size() - 2 * exc));

  return 0;
}