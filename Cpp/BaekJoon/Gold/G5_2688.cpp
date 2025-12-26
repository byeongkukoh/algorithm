#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> arr;
vector<bool> visited;
vector<bool> finished;
vector<bool> selected;

void dfs(int now) {
  visited[now] = true;

  int next = arr[now];

  if (!visited[next]) {
    dfs(next);
  } else if (!finished[next]) {
    int cur = next;
    while (cur != now) {
      selected[cur] = true;
      cur = arr[cur];
    }

    selected[now] = true;
  }

  finished[now] = true;
}

int main() {
  // 입력
  cin >> n;

  arr.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  // 초기화
  visited.assign(n + 1, false);
  finished.assign(n + 1, false);
  selected.assign(n + 1, false);

  // DFS
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) dfs(i);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (selected[i]) cnt++;
  }

  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    if (selected[i]) cout << i << "\n";
  }

  return 0;
}