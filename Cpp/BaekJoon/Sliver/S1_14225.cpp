#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int path[20];
int visited[20];

vector<int> vect;
vector<bool> isPossible(2000001, false);

int n;

void func(int now, int sum) {
  if (now == n) {
    isPossible[sum] = true;

    return;
  }

  // 현재 숫자를 포함하지 않는 경우
  func(now + 1, sum);

  // 현재 숫자를 포함하는 경우
  func(now + 1, sum + vect[now]);
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    vect.push_back(temp);
  }

  func(0, 0);

  for (int i = 1; i < 2000001; i++) {
    if (!isPossible[i]) {
      cout << i;
      break;
    }
  }
  return 0;
}