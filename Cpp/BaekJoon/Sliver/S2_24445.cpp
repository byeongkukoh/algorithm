#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m, r;
  cin >> n >> m >> r;

  vector<vector<int>> vect;
  vect.resize(n + 1);

  vector<int> visited;
  visited.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    vect[from].push_back(to);
    vect[to].push_back(from);
  }

  for (int i = 0; i < n + 1; i++) {
    sort(vect[i].begin(), vect[i].end(), greater<>());
  }

  queue<int> que;
  que.push(r);

  int cnt = 1;
  visited[r] = cnt;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < vect[now].size(); i++) {
      int next = vect[now][i];

      if (visited[next] != 0) continue;

      cnt++;
      visited[next] = cnt;
      que.push(next);
    }
  }

  for (int i = 1; i < n + 1; i++) {
    cout << visited[i] << "\n";
  }

  return 0;
}