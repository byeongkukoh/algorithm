#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
char vect[10];
int path[10];
int visited[10];

string min_value = "9999999999";
string max_value = "0";

void func(int now) {
  if (now == k + 1) {
    string temp = "";

    for (int i = 0; i < k + 1; i++) {
      temp += char(path[i]) + '0';
    }

    if (stoll(max_value) < stoll(temp)) max_value = temp;
    if (stoll(min_value) > stoll(temp)) min_value = temp;

    return;
  }

  for (int i = 0; i < 10; i++) {
    if (visited[i] == 1) continue;
    if (now > 0 && vect[now - 1] == '>' && path[now - 1] < i) continue;
    if (now > 0 && vect[now - 1] == '<' && path[now - 1] > i) continue;

    path[now] = i;
    visited[i] = 1;

    func(now + 1);

    path[now] = 0;
    visited[i] = 0;
  }

  return;
}

int main() {
  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> vect[i];
  }

  func(0);

  cout << max_value << "\n";
  cout << min_value;

  return 0;
}