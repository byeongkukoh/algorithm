#include <iostream>

using namespace std;

int N, M;
int used[10];
int path[10];

void permutation(int now) {
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";

    return;
  }

  for (int i = 1; i <= N; i++) {
    if (now > 0 && path[now - 1] >= i) {
      continue;
    }

    used[i] = 1;
    path[now] = i;

    permutation(now + 1);

    used[i] = 0;
    path[now] = 0;
  }
}

int main() {
  cin >> N >> M;

  permutation(0);

  return 0;
}