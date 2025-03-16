#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;

  bool operator<(Node right) const {
    if (dist > right.dist) return true;
    if (dist < right.dist) return false;

    return false;
  }
};

int node, edge;
vector<vector<Node>> vect;
vector<int> visited;

void dijkstra(int start) {
  priority_queue<Node> que;
  que.push({start, 0});

  fill(visited.begin(), visited.end(), INT_MAX);
  visited[start] = 0;

  while (!que.empty()) {
    Node now = que.top();
    que.pop();

    if (now.dist > visited[now.node]) continue;

    for (int i = 0; i < vect[now.node].size(); i++) {
      Node next = vect[now.node][i];
      int nextdist = now.dist + next.dist;

      if (nextdist >= visited[next.node]) continue;

      visited[next.node] = nextdist;
      que.push({next.node, nextdist});
    }
  }
}

int main() {
  cin >> node >> edge;

  vect.resize(node + 1);
  visited.resize(node + 1, INT_MAX);

  for (int i = 0; i < edge; i++) {
    int from, to, dist;
    cin >> from >> to >> dist;

    vect[from].push_back({to, dist});
    vect[to].push_back({from, dist});
  }

  int v1, v2;
  cin >> v1 >> v2;

  int min_dist = INT_MAX;

  if (v2 == 1 && v1 == node) {
    dijkstra(1);

    cout << visited[node];

    return 0;
  }

  // 1 -> v1 -> v2 -> n
  int temp = 0;
  dijkstra(1);  // 1 -> v1
  if (visited[v1] == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[v1];

  dijkstra(v1);  // v2 -> v1
  if (visited[v2] == INT_MAX || temp == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[v2];

  dijkstra(v2);  // v2 -> N
  if (visited[node] == INT_MAX || temp == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[node];

  min_dist = min(min_dist, temp);

  // 1 -> v2 -> v1 -> n
  temp = 0;
  dijkstra(1);  // 1 -> v2
  if (visited[v2] == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[v2];

  dijkstra(v2);  // v2 -> v1
  if (visited[v1] == INT_MAX || temp == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[v1];

  dijkstra(v1);  // v2 -> N
  if (visited[node] == INT_MAX || temp == INT_MAX)
    temp = INT_MAX;
  else
    temp += visited[node];

  min_dist = min(min_dist, temp);

  if (min_dist == INT_MAX) {
    cout << -1;
  } else {
    cout << min_dist;
  }

  return 0;
}