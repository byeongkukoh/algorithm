#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  queue<int> que;

  cin >> n;

  int cnt = 0;
  vector<int> dat(n + 1, 0);
  int total = 0;
  int res = 0;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    que.push(temp);

    if (dat[temp] == 0) cnt++;

    dat[temp]++;
    total++;

    while (cnt >= 3) {
      int tmp = que.front();
      que.pop();

      dat[tmp]--;
      total--;

      if (dat[tmp] == 0) cnt--;
    }

    if (total > res) res = total;
  }

  cout << res;

  return 0;
}