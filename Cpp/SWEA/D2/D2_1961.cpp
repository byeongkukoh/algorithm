#include <iostream>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int n;
    cin >> n;

    vector<vector<int>> map;
    map.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> map[i][j];
      }
    }

    vector<vector<int>> ro_90;
    vector<vector<int>> ro_180;
    vector<vector<int>> ro_270;

    ro_90.assign(n, vector<int>(n, 0));
    ro_180.assign(n, vector<int>(n, 0));
    ro_270.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ro_90[j][n - i - 1] = map[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ro_180[j][n - i - 1] = ro_90[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ro_270[j][n - i - 1] = ro_180[i][j];
      }
    }

    cout << "#" << t + 1 << "\n";

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ro_90[i][j];
      }

      cout << " ";

      for (int j = 0; j < n; j++) {
        cout << ro_180[i][j];
      }

      cout << " ";

      for (int j = 0; j < n; j++) {
        cout << ro_270[i][j];
      }
      cout << "\n";
    }
  }

  return 0;
}