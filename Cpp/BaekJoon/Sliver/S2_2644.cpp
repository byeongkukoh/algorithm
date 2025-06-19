#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int start, end;
  cin >> start >> end;

  int m;
  cin >> m;

  vector<vector<int>> people;
  people.resize(n + 1);

  vector<int> dist;
  dist.resize(n + 1, -1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    people[from].push_back(to);
    people[to].push_back(from);
  }

  queue<int> que;
  que.push(start);

  dist[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < people[now].size(); i++) {
      int next = people[now][i];

      if (dist[next] != -1) continue;

      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }

  cout << dist[end];

  return 0;
}