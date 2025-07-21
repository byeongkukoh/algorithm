#include <iostream>
#include <string>
#include <vector>

using namespace std;

int r, c;
bool dat[26] = {false};

vector<string> map;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int cnt = 1;
int res = 0;

void dfs(int row, int col) {
  if (res < cnt) res = cnt;

  for (int i = 0; i < 4; i++) {
    int ny = row + dy[i];
    int nx = col + dx[i];

    if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
    if (dat[map[ny][nx] - 'A']) continue;

    dat[map[ny][nx] - 'A'] = true;
    cnt++;

    dfs(ny, nx);

    dat[map[ny][nx] - 'A'] = false;
    cnt--;
  }
}

int main() {
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    string temp;
    cin >> temp;

    map.push_back(temp);
  }

  dat[map[0][0] - 'A'] = true;

  dfs(0, 0);

  cout << res;

  return 0;
}