#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const {
    return cost > right.cost;  // 최소 힙
  }
};

int node, edge;  // 노드 개수 / 간선 수

vector<vector<Node>> graph;  // 그래프

// index: 노드번호 / value: 시작 노드에서 해당 정점까지의 거리
vector<int> visited;

void bfs(int start) {
  // 가중치 최단경로 -> 다익스트라
  priority_queue<Node> pque;
  pque.push({start, 0});

  visited[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (now.cost > visited[now.node]) continue;

    for (int i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];
      int nextdist = visited[now.node] + next.cost;

      if (nextdist >= visited[next.node]) continue;

      pque.push({next.node, nextdist});
      visited[next.node] = nextdist;
    }
  }
}

int main() {
  cin >> node >> edge;

  int k;  // 시작 노드
  cin >> k;

  graph.resize(node + 1);             // node 번호 1 ~ N;
  visited.resize(node + 1, INT_MAX);  // INT_MAX: 방문 X

  for (int i = 0; i < edge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
  }

  bfs(k);

  for (int i = 1; i <= node; i++) {
    if (visited[i] == INT_MAX) {
      cout << "INF\n";
    } else {
      cout << visited[i] << "\n";
    }
  }

  return 0;
}