#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {};

vector<vector<int>> graph;
vector<bool> visited1;
vector<bool> visited2;

void dfs(int now) {
  cout << now << " ";
  visited1[now] = true;

  for (int i = 0; i < graph[now].size(); i++) {
    int next = graph[now][i];

    if (visited1[next]) continue;

    dfs(graph[now][i]);
  }

  return;
}

void bfs(int start) {
  queue<int> que;
  que.push(start);
  visited2[start] = true;

  while (!que.empty()) {
    int now = que.front();
    cout << now << " ";
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];

      if (visited2[next]) continue;

      que.push(next);
      visited2[next] = true;
    }
  }

  return;
}

int main() {
  int n, m, v;
  cin >> n >> m >> v;

  graph.resize(n + 1);
  visited1.resize(n + 1, false);
  visited2.resize(n + 1, false);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 0; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(v);

  cout << "\n";

  bfs(v);

  return 0;
}