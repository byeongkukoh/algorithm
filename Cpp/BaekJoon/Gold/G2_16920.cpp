#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Play {
  long long player;
  long long turn;
  long long check;
  long long y;
  long long x;
  long long id;

  bool operator<(const Play& right) const {
    if (turn != right.turn) return turn > right.turn;
    if (player != right.player) return player > right.player;

    return id > right.id;
  }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

long long map[1001][1001];

int main() {
  int count[10] = {0};
  long long current_id = 0;

  int n, m, p;
  cin >> n >> m >> p;

  int S[10] = {0};
  for (int i = 1; i <= p; i++) {
    cin >> S[i];
  }

  priority_queue<Play> pque;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      if (temp[j] == '.') {
        map[i][j] = -1;
      } else if (temp[j] == '#') {
        map[i][j] = 0;
      } else {
        int temp_ply = int(temp[j]) - 48;
        map[i][j] = temp_ply;
        pque.push({temp_ply, 1, 1, i, j, current_id++});
      }
    }
  }

  while (!pque.empty()) {
    Play now = pque.top();
    pque.pop();

    for (int i = 0; i < 4; i++) {
      long long ny = now.y + dy[i];
      long long nx = now.x + dx[i];

      if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
      // if (map[ny][nx] == 0) continue;
      if (map[ny][nx] != -1) continue;

      if (now.check == S[now.player] * now.turn) {
        map[ny][nx] = now.player;
        pque.push(
            {now.player, now.turn + 1, now.check + 1, ny, nx, current_id++});
      } else {
        map[ny][nx] = now.player;
        pque.push({now.player, now.turn, now.check + 1, ny, nx, current_id++});
      }
    }
  }

  for (int i = 1; i <= p; i++) {
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (map[row][col] == i) {
          count[i]++;
        }
      }
    }
  }

  for (int i = 1; i <= p; i++) {
    cout << count[i] << " ";
  }

  return 0;
}