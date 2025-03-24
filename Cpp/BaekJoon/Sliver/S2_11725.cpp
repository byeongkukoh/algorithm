#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph;
  vector<int> parent;

  graph.resize(n + 1);
  parent.resize(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];

      if (parent[next] != 0) continue;

      que.push(next);
      parent[next] = now;
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << parent[i] << "\n";
  }

  return 0;
}