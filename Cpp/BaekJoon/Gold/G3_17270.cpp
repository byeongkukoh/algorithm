#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(const Node& other) const {
    if (cost != other.cost) return cost > other.cost;

    return false;
  }
};

struct Result {
  int node;
  int jDist;
  int sDist;
  int sum_dist;

  bool operator<(const Result& other) const {
    if (sum_dist != other.sum_dist) return sum_dist > other.sum_dist;
    if (jDist != other.jDist) return jDist > other.jDist;
    if (node != other.node) return node > other.node;

    return false;
  }
};

void dijkstra(vector<vector<Node>>& graph, vector<int>& dist, int start);

int main() {
  int V, M;
  cin >> V >> M;

  vector<vector<Node>> graph;
  graph.assign(V + 1, vector<Node>());
  for (int i = 0; i < M; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  int J, S;
  cin >> J >> S;

  vector<int> ji_dist;
  ji_dist.assign(V + 1, INT_MAX);

  dijkstra(graph, ji_dist, J);

  vector<int> sung_dist;
  sung_dist.assign(V + 1, INT_MAX);

  dijkstra(graph, sung_dist, S);

  priority_queue<Result> result;
  int min_sum_dist = INT_MAX;

  for (int i = 1; i < V + 1; i++) {
    // 출발 위치는 약속장소 X
    if (i == J || i == S) continue;

    int sum_dist = ji_dist[i] + sung_dist[i];
    min_sum_dist = min(min_sum_dist, sum_dist);

    result.push({i, ji_dist[i], sung_dist[i], sum_dist});
  }

  while (!result.empty()) {
    Result now = result.top();
    result.pop();

    // 최단 거리가 아니면,
    if (now.sum_dist > min_sum_dist) {
      cout << -1;
      return 0;
    }

    // 지헌이 더 오래 걸리면,
    if (now.jDist > now.sDist) continue;

    cout << now.node;
    return 0;
  }

  cout << -1;

  return 0;
}

void dijkstra(vector<vector<Node>>& graph, vector<int>& dist, int start) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.cost) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      int nNode = graph[now.node][i].node;
      int nCost = graph[now.node][i].cost + now.cost;

      if (dist[nNode] <= nCost) continue;

      pque.push({nNode, nCost});
      dist[nNode] = nCost;
    }
  }
}