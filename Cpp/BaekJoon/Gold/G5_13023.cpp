#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> people;
vector<bool> visited;

int n, m;
bool found = false;

void dfs(int now, int cnt) {
  if (found) return;

  if (cnt == 5) {
    found = true;
    return;
  }

  for (int i = 0; i < people[now].size(); i++) {
    int next = people[now][i];

    if (visited[next]) continue;

    visited[next] = true;

    dfs(next, cnt + 1);

    visited[next] = false;
  }
}

int main() {
  cin >> n >> m;

  people.resize(n);
  visited.resize(n, false);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    people[a].push_back(b);
    people[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    visited[i] = true;

    dfs(i, 1);

    visited[i] = false;

    if (found) {
      cout << 1;
      return 0;
    }
  }

  cout << 0;

  return 0;
}