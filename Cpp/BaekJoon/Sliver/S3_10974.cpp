#include <iostream>

using namespace std;

int N;
int used[10];
int path[10];

void func(int now) {
  // 탈출 조건
  if (now == N) {
    for (int i = 0; i < N; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";
    return;
  }

  // 재귀 조건
  for (int i = 1; i <= N; i++) {
    if (used[i] == 1) {
      continue;
    }

    used[i] = 1;
    path[now] = i;
    func(now + 1);

    used[i] = 0;
    path[now] = 0;
  }
  return;
}

int main() {
  cin >> N;

  func(0);

  return 0;
}