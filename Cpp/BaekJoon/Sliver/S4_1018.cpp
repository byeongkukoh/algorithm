#include <climits>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string WB[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                  "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
  string BB[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                  "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

  int N, M;
  cin >> N >> M;

  string map[50];

  for (int i = 0; i < N; i++) {
    cin >> map[i];
  }

  int min = INT_MAX;

  for (int i = 0; i < N - 7; i++) {
    for (int j = 0; j < M - 7; j++) {
      int cnt = 0;

      for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
          if (map[i + row][j + col] != WB[row][col]) {
            cnt++;
          }
        }
      }

      if (min > cnt) min = cnt;

      cnt = 0;

      for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
          if (map[i + row][j + col] != BB[row][col]) {
            cnt++;
          }
        }
      }

      if (min > cnt) min = cnt;
    }
  }

  cout << min;

  return 0;
}
