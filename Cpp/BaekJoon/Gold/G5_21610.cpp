#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int row;
  int col;
};

int N, M;
vector<vector<int>> bucket;

// 방향은 1번부터 8번까지 정수로 표현
// 0, ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

// 구름 확인
int bdy[] = {0, -1, -1, 0};
int bdx[] = {0, 0, 1, 1};

int main() {
  cin >> N >> M;

  bucket.assign(
      N + 1, vector<int>(N + 1, 0));  // 왼쪽 상단: (1, 1) | 오른쪽 하단: (N, N)

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      cin >> bucket[i][j];
    }
  }

  // 초기 구름 위치
  queue<Node> cloud_loc;
  Node cloud = {N, 1};
  for (int i = 0; i < 4; i++) {
    int ny = (cloud.row + bdy[i]) % N == 0 ? N : (cloud.row + bdy[i]) % N;
    int nx = (cloud.col + bdx[i]) % N == 0 ? N : (cloud.col + bdx[i]) % N;

    cloud_loc.push({ny, nx});
  }

  // 반복 진행
  for (int m = 0; m < M; m++) {
    int dir, s;  // 방향, 거리
    cin >> dir >> s;

    // 비 내림
    vector<Node> rainy_loc;
    vector<vector<bool>> check_cloud(N + 1, vector<bool>(N + 1, false));
    while (!cloud_loc.empty()) {
      Node now = cloud_loc.front();
      cloud_loc.pop();

      Node next = {-1, -1};

      next.row = (now.row + dy[dir] * (s % N) + N - 1) % N + 1;
      next.col = (now.col + dx[dir] * (s % N) + N - 1) % N + 1;

      bucket[next.row][next.col] += 1;

      rainy_loc.push_back(next);
      check_cloud[next.row][next.col] = true;
    }

    // 물 복사 버그
    for (size_t i = 0; i < rainy_loc.size(); i++) {
      Node now = rainy_loc[i];

      int cnt = 0;

      // ↖, ↗, ↘, ↙
      int wdy[] = {-1, -1, 1, 1};
      int wdx[] = {-1, 1, 1, -1};

      for (int i = 0; i < 4; i++) {
        int nRow = now.row + wdy[i];
        int nCol = now.col + wdx[i];

        if (nRow < 1 || nCol < 1 || nRow > N || nCol > N) continue;

        // 물이 있으면 cnt++
        if (bucket[nRow][nCol] != 0) cnt++;
      }

      bucket[now.row][now.col] += cnt;
    }

    // 구름 생성
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        if (check_cloud[i][j]) continue;
        if (bucket[i][j] < 2) continue;

        bucket[i][j] -= 2;
        cloud_loc.push({i, j});
      }
    }
  }

  int result = 0;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      result += bucket[i][j];
    }
  }

  cout << result;

  return 0;
}