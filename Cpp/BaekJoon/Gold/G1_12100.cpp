#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int maxValue = 0;

vector<vector<int>> sliding(int dir, vector<vector<int>> board) {
  // 0: 위 | 1: 아래 | 2: 왼쪽 | 3: 오른쪽
  // 위로 옮기기
  if (dir == 0) {
    for (int col = 0; col < N; col++) {
      queue<int> que;

      for (int row = 0; row < N; row++) {
        if (board[row][col] != 0) {
          que.push(board[row][col]);
        }

        board[row][col] = 0;
      }

      int idx = 0;
      while (!que.empty()) {
        int now = que.front();
        que.pop();

        if (board[idx][col] == 0) {
          board[idx][col] = now;
        } else if (board[idx][col] == now) {
          board[idx][col] += now;
          idx++;
        } else {
          idx++;
          board[idx][col] = now;
        }
      }
    }
  }

  // 아래로 옮기기
  if (dir == 1) {
    for (int col = 0; col < N; col++) {
      queue<int> que;

      for (int row = N - 1; row >= 0; row--) {
        if (board[row][col] != 0) {
          que.push(board[row][col]);
        }

        board[row][col] = 0;
      }

      int idx = N - 1;
      while (!que.empty()) {
        int now = que.front();
        que.pop();

        if (board[idx][col] == 0) {
          board[idx][col] = now;
        } else if (board[idx][col] == now) {
          board[idx][col] += now;
          idx--;
        } else {
          idx--;
          board[idx][col] = now;
        }
      }
    }
  }

  // 왼쪽으로 옮기기
  if (dir == 2) {
    for (int row = 0; row < N; row++) {
      queue<int> que;

      for (int col = 0; col < N; col++) {
        if (board[row][col] != 0) {
          que.push(board[row][col]);
        }

        board[row][col] = 0;
      }

      int idx = 0;
      while (!que.empty()) {
        int now = que.front();
        que.pop();

        if (board[row][idx] == 0) {
          board[row][idx] = now;
        } else if (board[row][idx] == now) {
          board[row][idx] += now;
          idx++;
        } else {
          idx++;
          board[row][idx] = now;
        }
      }
    }
  }

  // 오른쪽으로 옮기기
  if (dir == 3) {
    for (int row = 0; row < N; row++) {
      queue<int> que;

      for (int col = N - 1; col >= 0; col--) {
        if (board[row][col] != 0) {
          que.push(board[row][col]);
        }

        board[row][col] = 0;
      }

      int idx = N - 1;
      while (!que.empty()) {
        int now = que.front();
        que.pop();

        if (board[row][idx] == 0) {
          board[row][idx] = now;
        } else if (board[row][idx] == now) {
          board[row][idx] += now;
          idx--;
        } else {
          idx--;
          board[row][idx] = now;
        }
      }
    }
  }

  return board;
}

void simulator(int now, vector<vector<int>> board) {
  if (now >= 10) {
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        if (board[row][col] > maxValue) {
          maxValue = board[row][col];
        }
      }
    }

    return;
  }

  for (int dir = 0; dir < 4; dir++) {
    vector<vector<int>> nextBoard = sliding(dir, board);

    simulator(now + 1, nextBoard);
  }
}

int main() {
  cin >> N;

  vector<vector<int>> board(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  simulator(0, board);

  cout << maxValue;

  return 0;
}