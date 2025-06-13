#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> NODE;
vector<int> dist;

void bfs(int start) {
  queue<int> que;
  que.push(start);

  dist[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < NODE[now].size(); i++) {
      int next = NODE[now][i];

      if (dist[next] != -1) continue;

      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }
}

int main() {
  cin >> n >> m;

  NODE.resize(n + 1);
  dist.resize(n + 1, -1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    NODE[from].push_back(to);
    NODE[to].push_back(from);
  }

  for (int i = 1; i < n + 1; i++) {
    sort(NODE[i].begin(), NODE[i].end());
  }

  bfs(1);

  int max_dist = 0;
  int max_index = 0;
  int count = 0;
  for (int i = 1; i < n + 1; i++) {
    if (dist[i] > max_dist) {
      max_dist = dist[i];
      count = 1;
      max_index = i;
    } else if (dist[i] == max_dist) {
      count += 1;
    }
  }

  cout << max_index << " " << max_dist << " " << count;

  return 0;
}