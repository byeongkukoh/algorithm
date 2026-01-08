#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coord {
  int row;
  int col;
};

void bfs(int N, int M, Coord start, const vector<vector<int>>& cheese,
         vector<Coord>& delCheese) {
  vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, false));

  queue<Coord> que;
  que.push(start);

  visited[start.row][start.col] = true;

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  while (!que.empty()) {
    Coord now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.row + dy[i];
      int nx = now.col + dx[i];

      if (ny < 0 || ny > N + 1 || nx < 0 || nx > M + 1) continue;
      if (visited[ny][nx]) continue;

      if (cheese[ny][nx] == 1) {
        delCheese.push_back({ny, nx});
        visited[ny][nx] = true;
        continue;
      }

      que.push({ny, nx});
      visited[ny][nx] = true;
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  int cntCheese = 0;

  vector<vector<int>> cheese(N + 2, vector<int>(M + 2, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> cheese[i][j];

      if (cheese[i][j] == 1) cntCheese++;
    }
  }

  int hour = 0;
  while (cntCheese != 0) {
    hour++;

    vector<Coord> delCheese;

    bfs(N, M, {0, 0}, cheese, delCheese);

    if (cntCheese - delCheese.size() == 0) {
      cout << hour << "\n" << cntCheese;
      return 0;
    }

    cntCheese = cntCheese - delCheese.size();

    for (size_t i = 0; i < delCheese.size(); i++) {
      cheese[delCheese[i].row][delCheese[i].col] = 0;
    }
  }

  return 0;
}