#include <algorithm>
#include <iostream>

using namespace std;

int N, SCORE;
int path[110];
bool used[110] = {false};
int S[110];
int res = 0;

void func(int now) {
  if (now == N) {
    // for (int i = 0; i < N; i++) {
    //   cout << path[i] << " ";
    // }

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        if (path[i] < path[j]) cnt++;
      }
    }

    if (cnt == SCORE) {
      res++;
    }

    // cout << "\n";

    return;
  }

  for (int i = 1; i <= N; i++) {
    if (path[now] != 0) {
      func(now + 1);

      return;

    } else {
      if (used[i]) continue;

      path[now] = i;
      used[i] = true;

      func(now + 1);

      path[now] = 0;
      used[i] = false;
    }
  }
}

int main() {
  cin >> N >> SCORE;

  for (int i = 0; i < N; i++) {
    cin >> path[i];
    if (path[i] != 0) {
      used[path[i]] = true;
    }
  }

  func(0);

  cout << res;

  return 0;
}