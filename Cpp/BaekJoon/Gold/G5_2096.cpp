#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int board[100000][3];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> board[i][j];
    }
  }

  if (n == 1) {
    cout << max(max(board[0][0], board[0][1]), board[0][2]) << " "
         << min(min(board[0][0], board[0][1]), board[0][2]);
    return 0;
  }

  vector<int> pre_score(3, 0);
  vector<int> cur_score(3, 0);

  for (int i = 0; i < 3; i++) {
    pre_score[i] = board[0][i];
  }

  // 최대값
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        cur_score[j] =
            max(pre_score[j] + board[i][j], pre_score[j + 1] + board[i][j]);
      } else if (j == 1) {
        cur_score[j] =
            max(max(pre_score[j - 1] + board[i][j], pre_score[j] + board[i][j]),
                pre_score[j + 1] + board[i][j]);
      } else if (j == 2) {
        cur_score[j] =
            max(pre_score[j - 1] + board[i][j], pre_score[j] + board[i][j]);
      }
    }

    pre_score = cur_score;
  }

  cout << max(max(cur_score[0], cur_score[1]), cur_score[2]) << " ";

  for (int i = 0; i < 3; i++) {
    pre_score[i] = board[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        cur_score[j] =
            min(pre_score[j] + board[i][j], pre_score[j + 1] + board[i][j]);
      } else if (j == 1) {
        cur_score[j] =
            min(min(pre_score[j - 1] + board[i][j], pre_score[j] + board[i][j]),
                pre_score[j + 1] + board[i][j]);
      } else if (j == 2) {
        cur_score[j] =
            min(pre_score[j - 1] + board[i][j], pre_score[j] + board[i][j]);
      }
    }

    pre_score = cur_score;
  }

  cout << min(min(cur_score[0], cur_score[1]), cur_score[2]);

  return 0;
}