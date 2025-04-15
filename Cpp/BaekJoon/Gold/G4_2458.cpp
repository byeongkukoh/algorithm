#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist;
  vector<vector<int>> re_dist;

  dist.resize(n + 1, vector<int>(n + 1, INT_MAX));
  re_dist.resize(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    dist[from][to] = 1;
    re_dist[to][from] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }

        if (re_dist[i][k] != INT_MAX && re_dist[k][j] != INT_MAX) {
          if (re_dist[i][j] > re_dist[i][k] + re_dist[k][j]) {
            re_dist[i][j] = re_dist[i][k] + re_dist[k][j];
          }
        }
      }
    }
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    int total = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;

      if (dist[i][j] != INT_MAX || re_dist[i][j] != INT_MAX) {
        total++;
      }
    }

    if (total == n - 1) {
      count++;
    }
  }

  cout << count;

  return 0;
}