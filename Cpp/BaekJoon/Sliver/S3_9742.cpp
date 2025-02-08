#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int used[128] = {0};
char path[20];

string str;
int N, cnt = 1;
bool check = false;

void init() {
  memset(used, 0, sizeof(used));
  memset(path, 0, sizeof(path));
  str = "";
  check = false;
  N = 0;
  cnt = 1;
}

void func(int now) {
  // 탈출 조건
  if (now == str.length()) {
    cnt++;

    if (cnt == N) {
      check = true;
      cout << str << " " << N << " = ";
      for (int i = 0; i < str.length(); i++) {
        cout << path[i];
      }
      cout << "\n";
    }

    return;
  }

  for (int i = 0; i < str.length(); i++) {
    // 판단
    if (used[str[i]] == 1) {
      continue;
    }

    // 재귀
    path[now] = str[i];
    used[str[i]] = 1;
    func(now + 1);

    // 복귀
    path[now] = 0;
    used[str[i]] = 0;
  }
}

int main() {
  while (!cin.eof()) {
    init();

    cin >> str >> N;

    func(0);

    if (!check) {
      cout << str << " " << N << " = " << "No permutation\n";
    }
  }

  return 0;
}