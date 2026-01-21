#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<long long>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

long long dfs(int row, int col) {
  if (visited[row][col] != -1) return visited[row][col];

  // 방문이 처음이면 1로 설정
  visited[row][col] = 1;

  for (int i = 0; i < 4; i++) {
    int nRow = row + dy[i];
    int nCol = col + dx[i];

    if (nRow < 0 || nCol < 0 || nRow >= N || nCol >= N) continue;

    if (visited[nRow][nCol] != 1 && map[row][col] < map[nRow][nCol]) {
      visited[row][col] = max(visited[row][col], dfs(nRow, nCol) + 1);
    } else if (map[row][col] < map[nRow][nCol]) {
      visited[row][col] = max(visited[row][col], visited[nRow][nCol] + 1);
    }
  }

  // 갈 수 있는 곳이 없으면 자기 자신 반환
  return visited[row][col];
}

int main() {
  cin >> N;

  map.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  visited.assign(N, vector<long long>(N, -1));

  long long result = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      result = max(result, dfs(i, j));
    }
  }

  cout << result;

  return 0;
}