#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;
};

int n, m;
vector<vector<int>> friends;
vector<int> visited;

int min_dist = INT_MAX;
int result = 0;

void bfs(int start) {
  visited.assign(n + 1, -1);

  queue<int> que;
  que.push(start);

  visited[start] = 0;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 0; i < friends[now].size(); i++) {
      int next = friends[now][i];
      int nextdist = visited[now] + 1;

      if (visited[next] != -1) continue;
      if (visited[next] != -1 && visited[next] < nextdist) continue;

      que.push(next);
      visited[next] = nextdist;
    }
  }

  int temp = 0;

  for (int i = 1; i <= n; i++) {
    temp += visited[i];
  }

  if (min_dist > temp) {
    min_dist = temp;
    result = start;
  }
}

int main() {
  cin >> n >> m;

  friends.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    friends[from].push_back(to);
    friends[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    sort(friends[i].begin(), friends[i].end());
  }

  for (int i = 1; i <= n; i++) {
    bfs(i);
  }

  cout << result;

  return 0;
}