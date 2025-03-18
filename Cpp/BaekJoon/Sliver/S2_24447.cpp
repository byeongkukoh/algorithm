#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  long long n, m, r;
  cin >> n >> m >> r;

  vector<vector<long long>> graph(n + 1);
  vector<long long> depth(n + 1, -1);
  vector<long long> order(n + 1, 0);

  for (int i = 0; i < m; i++) {
    long long from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  queue<long long> que;
  que.push(r);  // 시작점 r

  long long num = 1;
  order[r] = num;
  depth[r] = 0;

  while (!que.empty()) {
    long long now = que.front();
    que.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      long long next = graph[now][i];

      if (order[next] != 0) continue;

      num++;
      order[next] = num;
      depth[next] = depth[now] + 1;

      que.push(next);
    }
  }

  // for (long long i = 1; i <= n; i++) {
  //   cout << order[i] << " ";
  // }

  // cout << "\n";

  // for (long long i = 1; i <= n; i++) {
  //   cout << depth[i] << " ";
  // }

  long long result = 0;
  for (int i = 1; i <= n; i++) {
    result = result + order[i] * depth[i];
  }

  cout << result;

  return 0;
}