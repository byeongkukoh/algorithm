#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

struct Move {
  int start;
  int time;
};

int n, p, m;

vector<vector<Node>> graph;
vector<vector<int>> dist;
vector<Move> start;

void init() {
  graph.clear();
  start.clear();
  dist.clear();

  cin >> n >> p >> m;

  graph.resize(n + 1);
  dist.resize(p + 1, vector<int>(n + 1, INT_MAX));
  start.resize(p + 1, {0, 0});

  for (int i = 1; i <= p; i++) {
    cin >> start[i].start >> start[i].time;
  }

  for (int i = 0; i < m; i++) {
    int cost, city, s_city;
    cin >> cost >> city >> s_city;

    for (int j = 1; j < city; j++) {
      int e_city;
      cin >> e_city;

      graph[s_city].push_back({e_city, cost});
      graph[e_city].push_back({s_city, cost});

      s_city = e_city;
    }
  }

  return;
}

void bfs(int start, vector<int>& dist) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < graph[now.node].size(); i++) {
      Node next = graph[now.node][i];
      int nextDist = now.dist + next.dist;

      if (dist[next.node] <= nextDist) continue;

      pque.push({next.node, nextDist});
      dist[next.node] = nextDist;
    }
  }
}

int main() {
  int test_case;
  cin >> test_case;

  for (int t = 1; t <= test_case; t++) {
    init();

    for (int i = 1; i <= p; i++) {
      bfs(start[i].start, dist[i]);
    }

    int result = INT_MAX;

    for (int i = 1; i <= n; i++) {
      int temp = 0;
      bool check = true;

      for (int j = 1; j <= p; j++) {
        if (dist[j][i] == INT_MAX) {
          check = false;
          break;
        }

        temp = max(temp, dist[j][i] * start[j].time);
      }

      if (check && result > temp) result = temp;
    }

    if (result == INT_MAX) result = -1;

    cout << "Case #" << t << ": " << result << "\n";
  }

  return 0;
}