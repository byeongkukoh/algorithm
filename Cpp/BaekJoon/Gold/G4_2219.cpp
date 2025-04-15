#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist;
  dist.resize(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    dist[from][to] = cost;
    dist[to][from] = cost;
  }

  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
  }

  int min_value = INT_MAX;
  int result = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;

      temp += dist[i][j];
    }

    if (min_value > temp) {
      min_value = temp;
      result = i;
    }
  }

  cout << result;

  return 0;
}