#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long time;

  bool operator<(Node right) const { return time > right.time; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> vision;
  vision.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> vision[i];
  }

  vector<vector<Node>> map;
  vector<long long> visited;
  map.resize(n);
  visited.resize(n, LLONG_MAX);

  for (int i = 0; i < m; i++) {
    int from, to, time;
    cin >> from >> to >> time;

    map[from].push_back({to, time});
    map[to].push_back({from, time});
  }

  priority_queue<Node> pque;
  pque.push({0, 0});

  visited[0] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.time) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      long long nextTime = now.time + next.time;

      if (visited[next.node] <= nextTime) continue;
      if (next.node != n - 1 && vision[next.node] == 1) continue;

      pque.push({next.node, nextTime});
      visited[next.node] = nextTime;
    }
  }

  if (visited[n - 1] == LLONG_MAX) {
    cout << -1;
  } else {
    cout << visited[n - 1];
  }

  return 0;
}