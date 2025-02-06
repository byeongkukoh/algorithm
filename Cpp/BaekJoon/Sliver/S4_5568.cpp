#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, k;
set<int> s;
vector<string> vect;

string path[10];
int used[10] = {0};

void func(int now) {
  // 탈출 조건
  if (now == k) {
    string temp = "";
    for (int i = 0; i < k; i++) {
      temp += path[i];
    }
    s.insert(stoi(temp));
    return;
  }

  for (int i = 0; i < n; i++) {
    // if (used[stoi(vect[i])] == 1) {
    if (used[i] == 1) {
      continue;
    }
    path[now] = vect[i];
    used[i] = 1;

    func(now + 1);

    path[now].pop_back();
    used[i] = 0;
  }

  return;
}

int main() {
  // n & k 입력
  cin >> n >> k;

  // 숫자 카드 입력
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    vect.push_back(temp);
  }

  // 재귀 함수 호출
  func(0);

  // 결과 출력
  cout << s.size();

  return 0;
}