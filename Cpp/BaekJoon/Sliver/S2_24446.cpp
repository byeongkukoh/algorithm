#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int depth;
};

int main() {
  int u, v, r;
  cin >> u >> v >> r;

  vector<vector<int>> graph;
  vector<int> visited;

  graph.resize(u + 1);
  visited.resize(u + 1, -1);

  for (int i = 0; i < v; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 0; i <= u; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  // BFS 시작
  queue<Node> que;
  que.push({r, 0});  // start node = r, depth = 0

  visited[r] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < graph[now.node].size(); i++) {
      int next = graph[now.node][i];
      int nextDepth = now.depth + 1;

      if (visited[next] != -1) continue;

      visited[next] = nextDepth;
      que.push({next, nextDepth});
    }
  }

  for (int i = 1; i <= u; i++) {
    cout << visited[i] << "\n";
  }

  return 0;
}