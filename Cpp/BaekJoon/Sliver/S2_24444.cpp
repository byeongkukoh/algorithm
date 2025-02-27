#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;

void bfs(int start) {
  queue<int> que;
  que.push(start);

  int count = 1;

  visited[start] = true;
  order[start] = count;

  count++;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];

      if (visited[next]) continue;

      visited[next] = true;
      que.push(next);

      order[next] = count;
      count++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> r;

  graph.resize(n + 1);
  visited.resize(n + 1, false);
  order.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 0; i < n + 1; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  bfs(r);

  for (int i = 1; i < n + 1; i++) {
    cout << order[i] << "\n";
  }

  return 0;
}