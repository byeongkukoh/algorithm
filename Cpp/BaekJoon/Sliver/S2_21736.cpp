#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

vector<string> map;
vector<vector<int>> visited;

vector<Node> person;
Node doyeon;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int row, int col, int n, int m) {
  queue<Node> que;
  que.push({row, col});

  visited[row][col] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map[ny][nx] == 'X') continue;
      if (visited[ny][nx] == 1) continue;

      que.push({ny, nx});
      visited[ny][nx] = 1;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  map.resize(n);
  visited.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    cin >> map[i];

    for (int j = 0; j < m; j++) {
      if (map[i][j] == 'I') {
        doyeon.row = i;
        doyeon.col = j;
      }

      if (map[i][j] == 'P') {
        person.push_back({i, j});
      }
    }
  }

  bfs(doyeon.row, doyeon.col, n, m);

  int cnt = 0;

  for (int i = 0; i < person.size(); i++) {
    Node p = person[i];

    if (visited[p.row][p.col] == 1) {
      cnt++;
    }
  }

  if (cnt == 0)
    cout << "TT\n";
  else
    cout << cnt << "\n";

  return 0;
}