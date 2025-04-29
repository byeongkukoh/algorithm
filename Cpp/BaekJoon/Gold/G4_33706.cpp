#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;

void bfs(int start) {
  queue<int> que;
  que.push(start);

  visited[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];
      int nextDist = visited[now] + 1;

      if (visited[next] != INT_MAX) continue;

      visited[next] = nextDist;
      que.push(next);
    }
  }

  return;
}

int main() {
  int n, m;
  cin >> n >> m;

  graph.resize(n + 1);
  visited.resize(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    if (from < to) {
      graph[from].push_back(to);
    } else {
      graph[to].push_back(from);
    }
  }

  bfs(1);

  for (int i = 1; i <= n; i++) {
    if (visited[i] == INT_MAX) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}