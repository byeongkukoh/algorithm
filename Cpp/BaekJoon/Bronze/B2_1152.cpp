#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  getline(cin, str);

  int count = 0;

  if (str.length() == 1 && str[0] == ' ') {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < str.length(); i++) {
    if (i == 0 && str[i] == ' ') continue;
    if (i == str.length() - 1 && str[i] == ' ') continue;
    if (str[i] == ' ') {
      count++;
    }
  }

  cout << count + 1;

  return 0;
}

// C++에서 공백을 포함한 문자열을 받을 때 >> getline(cin, str) 함수 사용
// 문제에서 "틀렸습니다"가 나오는 경우, 공백만 있는 문자열 처리에 대해
// 확인해보기