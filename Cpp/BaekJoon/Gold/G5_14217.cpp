#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> MAP;
vector<int> dist;

void bfs(int start) {
  dist.assign(n + 1, -1);

  queue<int> que;
  que.push(start);

  dist[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < MAP[now].size(); i++) {
      int next = MAP[now][i];

      if (next == 0) continue;
      if (dist[next] != -1) continue;

      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }
}

int main() {
  cin >> n >> m;

  MAP.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    MAP[from].push_back(to);
    MAP[to].push_back(from);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int a, from, to;
    cin >> a >> from >> to;

    if (a == 1) {
      MAP[from].push_back(to);
      MAP[to].push_back(from);
    } else {
      for (int j = 0; j < MAP[from].size(); j++) {
        if (MAP[from][j] == to) {
          MAP[from].erase(MAP[from].begin() + j);
          break;
        }
      }

      for (int j = 0; j < MAP[to].size(); j++) {
        if (MAP[to][j] == from) {
          MAP[to].erase(MAP[to].begin() + j);
          break;
        }
      }
    }

    bfs(1);

    for (int j = 1; j < n + 1; j++) {
      cout << dist[j] << " ";
    }
    cout << "\n";
  }

  return 0;
}