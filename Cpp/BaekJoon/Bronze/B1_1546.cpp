#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  float scores[1000], max = 0;

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
    if (max < scores[i]) {
      max = scores[i];
    }
  }

  float new_scores[1000];
  float new_sum = 0;
  for (int i = 0; i < n; i++) {
    new_scores[i] = scores[i] / max * 100;
    new_sum += new_scores[i];
  }

  cout << new_sum / float(n);

  return 0;
}