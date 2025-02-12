#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int numbers[10];
vector<int> path;

void func(int now) {
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  for (int i = 0; i < N; i++) {
    path.push_back(numbers[i]);

    func(now + 1);

    path.pop_back();
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  sort(numbers, numbers + N);

  func(0);

  return 0;
}