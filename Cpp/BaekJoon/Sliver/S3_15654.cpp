#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> path;
int used[10000] = {0};

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
  for (int i = 0; i < N; i++) {
    // 판단
    if (used[numbers[i]] == 1) continue;

    path.push_back(numbers[i]);
    used[numbers[i]] = 1;
    permutation(now + 1);

    path.pop_back();
    used[numbers[i]] = 0;
  }
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