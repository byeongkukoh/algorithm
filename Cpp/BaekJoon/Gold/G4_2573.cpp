#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int n, m;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> cnt;

void bfs(Node start) {
  queue<Node> que;
  que.push(start);
  visited[start.row][start.col] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map[ny][nx] == 0) continue;
      if (visited[ny][nx] == 1) continue;

      visited[ny][nx] = 1;
      que.push({ny, nx});
    }
  }
}

int main() {
  cin >> n >> m;

  map.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  int year = 0;

  while (true) {
    year++;

    // 해양 접촉 면 계산
    cnt.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] == 0) continue;

        for (int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
          if (map[ny][nx] == 0) cnt[i][j]++;
        }
      }
    }

    // 빙산 높이 갱신
    vector<vector<int>> new_map = map;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        new_map[i][j] -= cnt[i][j];
        if (new_map[i][j] < 0) new_map[i][j] = 0;
      }
    }
    map = new_map;

    // 섬 개수 확인
    visited.assign(n, vector<int>(m, 0));
    int island = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] != 0 && visited[i][j] == 0) {
          bfs({i, j});
          island++;
        }
      }
    }

    if (island == 0) {
      cout << 0 << '\n';  // 모두 녹은 경우
      break;
    }

    if (island >= 2) {
      cout << year << '\n';  // 분리된 순간 출력
      break;
    }
  }

  return 0;
}
