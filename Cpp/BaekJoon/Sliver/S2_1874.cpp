#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  stack<int> stk;
  vector<char> result;  // 연산 결과 저장

  int num = 1;  // push할 숫자 (1부터 n까지 증가)

  for (int i = 0; i < n; i++) {
    int target;
    cin >> target;

    // target 값이 나올 때까지 push
    while (num <= target) {
      stk.push(num);
      result.push_back('+');
      num++;
    }

    // 스택의 top이 target과 같으면 pop
    if (!stk.empty() && stk.top() == target) {
      stk.pop();
      result.push_back('-');
    } else {
      cout << "NO\n";
      return 0;
    }
  }

  // 연산 결과 출력
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}