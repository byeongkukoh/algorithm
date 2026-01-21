#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> path;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dfs(int row, int col) {
  if (row == M - 1 && col == N - 1) return 1;

  // 이미 방문한 위치에 대해서는 값 반환
  if (path[row][col] != -1) return path[row][col];

  // 방문하지 않았으면 0으로 설정
  path[row][col] = 0;

  for (int i = 0; i < 4; i++) {
    int nRow = row + dy[i];
    int nCol = col + dx[i];

    if (nRow < 0 || nCol < 0 || nRow >= M || nCol >= N) continue;
    if (map[row][col] <= map[nRow][nCol]) continue;

    path[row][col] += dfs(nRow, nCol);
  }

  // 갈수 있는 길이 없으면 반환
  return path[row][col];
}

int main() {
  cin >> M >> N;

  map.assign(M, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  path.assign(M, vector<int>(N, -1));

  dfs(0, 0);

  cout << path[0][0];

  return 0;
}