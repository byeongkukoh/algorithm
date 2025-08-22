#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int n, m;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<int> count_id;
vector<vector<int>> grid;
vector<vector<int>> visited;

int bfs(Node start, int id) {
  queue<Node> que;
  que.push(start);

  int cnt = 1;
  visited[start.y][start.x] = id;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (grid[ny][nx] != 0) continue;
      if (visited[ny][nx] != -1) continue;

      que.push({ny, nx});
      visited[ny][nx] = id;
      cnt++;
    }
  }

  return cnt;
}

int main() {
  cin >> n >> m;

  grid.resize(n, vector<int>(m, 0));
  visited.resize(n, vector<int>(m, -1));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      grid[i][j] = int(temp[j] - '0');
    }
  }

  int id = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) continue;
      if (visited[i][j] != -1) continue;

      int temp = bfs({i, j}, id);
      count_id.push_back(temp);

      id++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        cout << 0;
        continue;
      }

      int temp = 0;
      int used[4] = {-1, -1, -1, -1};

      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx] == -1) continue;

        int idx = visited[ny][nx];
        bool check = false;

        for (int p = 0; p < 4; p++) {
          if (used[p] == idx) {
            check = true;
            break;
          }

          if (used[p] == -1) {
            used[p] = idx;
            break;
          }
        }

        if (check) continue;

        temp += count_id[idx];
      }

      cout << (temp + 1) % 10;
    }

    cout << "\n";
  }

  return 0;
}
