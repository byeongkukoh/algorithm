#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const { return cost > right.cost; }
};

vector<vector<Node>> graph;
vector<int> visited;
vector<int> path;

int n, m;

void dijkstra(int start, int x1, int x2) {
  visited.assign(n + 1, INT_MAX);  // 방문 기록 초기화

  priority_queue<Node> pque;
  pque.push({start, 0});

  visited[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.cost) continue;

    for (int i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];

      if ((now.node == x1 && next.node == x2) ||
          (now.node == x2 && next.node == x1))
        continue;
      int nextcost = now.cost + next.cost;

      if (visited[next.node] <= nextcost) continue;

      visited[next.node] = nextcost;
      pque.push({next.node, nextcost});
      path[next.node] = now.node;
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  path.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});  // 도로는 모두 양방향
    graph[to].push_back({from, cost});
  }

  dijkstra(1, 0, 0);  // start = 1

  int min_time = visited[n];

  // 최단 경로 복원
  vector<int> route;
  for (int i = n; i != 0; i = path[i]) {
    route.push_back(i);
  }

  int max_time = min_time;
  for (int i = 0; i < route.size() - 1; i++) {
    dijkstra(1, route[i], route[i + 1]);

    if (max_time < visited[n]) {
      max_time = visited[n];
    }
  }

  if (max_time == INT_MAX)
    cout << -1;
  else
    cout << max_time - min_time;

  //   for (int i = 0; i < route.size(); i++) {
  //     cout << route[i] << " ";
  //   }

  return 0;
}