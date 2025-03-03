#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int main() {
  while (1) {
    int width, height;
    cin >> width >> height;

    if (width == 0 && height == 0) break;

    vector<vector<int>> map;
    vector<vector<int>> visited;

    // map 및 visited 배열 초기화
    map.resize(height, vector<int>(width, 0));
    visited.resize(height, vector<int>(width, 0));

    // map 정보 입력
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        cin >> map[i][j];
      }
    }

    // 방향 배열 - 좌상, 상, 우상, 우, 우하, 하, 좌하, 좌
    int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    int cnt = 0;  // 섬 개수 카운팅

    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
        if (map[row][col] == 1) {
          cnt++;
          // BFS 기반 Flood Fill 수행
          queue<Node> que;
          que.push({row, col});

          visited[row][col] = 1;
          map[row][col] = 0;

          while (!que.empty()) {
            Node now = que.front();
            que.pop();

            map[now.y][now.x] = 0;

            for (int i = 0; i < 8; i++) {
              int ny = now.y + dy[i];
              int nx = now.x + dx[i];

              if (ny >= height || ny < 0 || nx >= width || ny < 0) continue;
              if (map[ny][nx] != 1) continue;
              if (visited[ny][nx] != 0) continue;

              visited[ny][nx] = 1;
              que.push({ny, nx});
            }
          }
        }
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}