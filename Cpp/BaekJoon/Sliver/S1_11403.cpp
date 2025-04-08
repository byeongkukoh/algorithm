#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;

void bfs(int start, int n);

int main() {
  int n;
  cin >> n;

  map.resize(n, vector<int>(n, 0));
  visited.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    bfs(i, n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

void bfs(int start, int n) {
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < n; i++) {
      if (map[now][i] == 0) continue;

      int next = i;

      if (visited[start][next] != 0) continue;

      visited[start][next] = 1;
      que.push(next);
    }
  }
}