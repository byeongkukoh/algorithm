#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> subset;

int N, S;
int cnt = 0;

// 백트래킹을 이용한 부분 수열 생성
void generateSubset(int index) {
  if (index == N) {
    if (!subset.empty()) {
      int sum = 0;
      for (int i = 0; i < subset.size(); i++) {
        sum += subset[i];
      }
      if (sum == S) {
        cnt++;
      }
    }

    return;
  }

  // 1. 현재 원소를 선택하는 경우
  subset.push_back(arr[index]);
  generateSubset(index + 1);

  // 2. 현재 원소를 선택하지 않는 경우
  subset.pop_back();
  generateSubset(index + 1);
}

int main() {
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    arr.push_back(num);
  }

  generateSubset(0);  // 부분 수열 생성 시작

  cout << cnt;

  return 0;
}