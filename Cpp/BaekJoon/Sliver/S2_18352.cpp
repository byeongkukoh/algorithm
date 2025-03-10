#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> dist;
vector<vector<int>> graph;

int n, m, k, x;

void bfs(int start) {
  queue<int> que;
  que.push(start);

  dist[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];

      if (dist[next] != -1) continue;

      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }
}

int main() {
  cin >> n >> m >> k >> x;

  graph.resize(n + 1);
  dist.resize(n + 1, -1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
  }

  bfs(x);

  bool cnt = false;
  for (int i = 0; i < dist.size(); i++) {
    if (dist[i] == k) {
      cout << i << "\n";
      cnt = true;
    }
  }

  if (!cnt) cout << -1;

  return 0;
}