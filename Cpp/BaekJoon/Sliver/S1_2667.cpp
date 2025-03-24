#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

int main() {
  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  vector<vector<int>> map;
  vector<vector<int>> apart;
  vector<int> count;

  int n;
  cin >> n;

  map.resize(n, vector<int>(n, 0));
  apart.resize(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < n; j++) {
      if (temp[j] == '0')
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }

  int nums = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1 && apart[i][j] == 0) {
        nums++;

        queue<Node> que;
        que.push({i, j});
        apart[i][j] = nums;

        int cnt = 1;

        while (!que.empty()) {
          Node now = que.front();
          que.pop();

          for (int k = 0; k < 4; k++) {
            int ny = now.y + dy[k];
            int nx = now.x + dx[k];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (map[ny][nx] != 1) continue;
            if (apart[ny][nx] != 0) continue;

            que.push({ny, nx});
            apart[ny][nx] = nums;

            cnt++;
          }
        }

        count.push_back(cnt);
      }
    }
  }

  sort(count.begin(), count.end());

  cout << nums << "\n";

  for (int i = 0; i < count.size(); i++) {
    cout << count[i] << "\n";
  }

  return 0;
}