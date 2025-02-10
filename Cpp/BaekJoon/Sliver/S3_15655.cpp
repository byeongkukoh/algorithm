#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int path[10] = {0};
int used[10000] = {0};

vector<int> numbers;

void permutation(int now) {
  // 탈출 조건
  if (now == M) {
    for (int i = 0; i < M; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";
    return;
  }

  // 재귀 조건
  for (int i = 0; i < N; i++) {
    if ((now > 0 && path[now - 1] > numbers[i]) || used[numbers[i]] == 1)
      continue;

    path[now] = numbers[i];
    used[numbers[i]] = 1;

    permutation(now + 1);

    path[now] = 0;
    used[numbers[i]] = 0;
  }

  return;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    numbers.push_back(num);
  }

  sort(numbers.begin(), numbers.end());

  permutation(0);

  return 0;
}