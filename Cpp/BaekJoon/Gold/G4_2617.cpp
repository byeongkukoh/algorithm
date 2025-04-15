#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist;
  dist.resize(n + 1, vector<int>(n + 1, INT_MAX));

  vector<vector<int>> redist;
  redist.resize(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    dist[from][to] = 1;
    redist[to][from] = 1;
  }

  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
    redist[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }

        if (redist[i][k] != INT_MAX && redist[k][j] != INT_MAX) {
          if (redist[i][j] > redist[i][k] + redist[k][j]) {
            redist[i][j] = redist[i][k] + redist[k][j];
          }
        }
      }
    }
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    int heavior = 0;
    int lighter = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;

      if (dist[i][j] != INT_MAX) heavior++;
      if (redist[i][j] != INT_MAX) lighter++;
    }

    if (heavior > n / 2 || lighter > n / 2) count++;
  }

  cout << count;

  return 0;
}