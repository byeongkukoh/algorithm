class Solution {
 public:
  struct Node {
    int node;
    int cost;

    bool operator<(const Node& other) const {
      if (cost != other.cost) return cost > other.cost;

      return false;
    }
  };

  void dijkstra(vector<vector<Node>>& graph, vector<int>& cost, int start) {
    priority_queue<Node> pque;
    pque.push({start, 0});

    cost[start] = 0;

    while (!pque.empty()) {
      Node now = pque.top();
      pque.pop();

      if (cost[now.node] < now.cost) continue;

      for (size_t i = 0; i < graph[now.node].size(); i++) {
        int next_node = graph[now.node][i].node;
        int next_cost = graph[now.node][i].cost + now.cost;

        if (cost[next_node] <= next_cost) continue;

        pque.push({next_node, next_cost});
        cost[next_node] = next_cost;
      }
    }
  }

  int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<Node>> graph(n);

    for (size_t i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      graph[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
    }

    vector<int> cost(n, INT_MAX);
    dijkstra(graph, cost, 0);

    if (cost[n - 1] == INT_MAX) return -1;

    return cost[n - 1];
  }
};