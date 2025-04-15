#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int m;
  cin >> m;

  vector<vector<int>> dist;
  dist.resize(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    if (dist[from][to] > cost) {
      dist[from][to] = cost;
    }
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

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == INT_MAX) {
        cout << 0 << " ";
      } else {
        cout << dist[i][j] << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}