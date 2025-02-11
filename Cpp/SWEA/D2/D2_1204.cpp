#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int order;
    cin >> order;

    int score[101] = {0};

    for (int i = 0; i < 1000; i++) {
      int test;
      cin >> test;

      score[test]++;
    }

    int resIndex = 0;
    for (int i = 0; i < 101; i++) {
      if (score[i] >= score[resIndex]) {
        resIndex = i;
      }
    }

    cout << "#" << order << " " << resIndex << "\n";
  }
}