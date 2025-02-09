#include <iostream>

using namespace std;

int N, M;
int path[10];  // 현재 숫자 저장

void permutation(int now) {
  // 탈출 코드
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  // 재귀 코드
  for (int i = 1; i <= N; i++) {
    // 판단
    if (now > 0 && path[now - 1] > i) continue;

    // 재귀
    path[now] = i;
    permutation(now + 1);

    path[now] = 0;
  }
}

int main() {
  cin >> N >> M;

  permutation(0);

  return 0;
}