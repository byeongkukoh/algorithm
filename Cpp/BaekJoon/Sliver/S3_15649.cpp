#include <iostream>

using namespace std;

int N, M;

int visited[10];
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
    if (visited[i] == 1) continue;

    path[now] = i;
    visited[i] = 1;

    permutation(now + 1);

    path[now] = 0;
    visited[i] = 0;
  }

  return;
}

int main() {
  cin >> N >> M;

  permutation(0);

  return 0;
}