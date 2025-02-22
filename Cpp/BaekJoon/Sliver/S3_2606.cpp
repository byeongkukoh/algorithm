#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> comp;
vector<bool> visited;
int cnt = 0;

void bfs(int start) {
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < comp[now].size(); i++) {
      int next = comp[now][i];
      if (visited[next]) continue;

      que.push(next);
      visited[next] = true;
      cnt++;
    }
  }
}

int main() {
  int node, edge;
  cin >> node >> edge;

  comp.resize(node + 1);
  visited.resize(node + 1, false);

  for (int i = 0; i < edge; i++) {
    int from, to;
    cin >> from >> to;

    comp[from].push_back(to);
    comp[to].push_back(from);
  }

  bfs(1);

  cout << cnt;

  return 0;
}