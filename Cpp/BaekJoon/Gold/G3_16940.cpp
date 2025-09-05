#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> map;
vector<int> visited;
vector<int> seq;

int bfs(int start) {
  if (seq[1] != 1) return 0;

  queue<int> que;
  que.push(start);

  int idx = 1;
  visited[start] = 1;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    idx++;
    int cnt = 0;
    for (size_t i = 0; i < map[now].size(); i++) {
      int next = map[now][i];

      if (visited[next] != -1) continue;

      visited[next] = idx;
      cnt++;
    }

    int s_idx = idx;
    int e_idx = idx + cnt - 1;

    for (int i = s_idx; i <= e_idx; i++) {
      if (visited[seq[i]] == -1) return 0;

      que.push(seq[i]);
    }

    idx = e_idx;
  }

  return 1;
}

int main() {
  cin >> n;

  map.resize(n + 1);
  visited.resize(n + 1, -1);
  seq.resize(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int from, to;
    cin >> from >> to;

    map[from].push_back(to);
    map[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;

    seq[i] = temp;
  }

  cout << bfs(1);

  return 0;
}