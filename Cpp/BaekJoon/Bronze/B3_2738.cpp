#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> A;
  vector<vector<int>> B;

  A.resize(n, vector<int>(m, 0));
  B.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << A[i][j] + B[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}