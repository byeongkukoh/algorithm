#include <iostream>

using namespace std;

int N, M;
int path[10];

void permutation(int now) {
  // 탈출 코드
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  // 재귀
  for (int i = 1; i < N + 1; i++) {
    // 재귀
    path[now] = i;
    permutation(now + 1);

    // 복귀
    path[now] = 0;
  }

  return;
}

int main() {
  cin >> N >> M;

  permutation(0);

  return 0;
}