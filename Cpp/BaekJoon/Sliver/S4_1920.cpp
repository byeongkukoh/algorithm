#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &arr, int key) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == key) {
      return 1;
    } else if (arr[mid] > key) {  // 왼쪽 부분 탐색
      right = mid - 1;
    } else {  // 오른쪽 부분 탐색
      left = mid + 1;
    }
  }

  return 0;  // 찾지 못한 경우
}

int main() {
  int N, M;
  vector<int> A;
  vector<int> B;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;

    A.push_back(temp);
  }

  sort(A.begin(), A.end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    int temp;
    cin >> temp;

    B.push_back(temp);
  }

  for (int j = 0; j < M; j++) {
    int res = binary_search(A, B[j]);

    cout << res << "\n";
  }

  return 0;
}