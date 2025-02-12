#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int numbers[10];
int path[10];

void func(int now) {
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (now > 0 && path[now - 1] > numbers[i]) continue;

    path[now] = numbers[i];

    func(now + 1);

    path[now] = 0;
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