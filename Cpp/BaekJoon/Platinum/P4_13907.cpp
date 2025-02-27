#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int node;
  int cost;
};

struct State {
  int cost, node, count;

  bool operator<(State right) const {
    if (cost > right.cost) return true;
    if (cost < right.cost) return false;

    return false;
  }
};

int node, edge, year;
int A, B;

vector<vector<Edge>> path;
vector<vector<int>> dist;

void dijkstra() {
  priority_queue<State> pque;
  pque.push({0, A, 0});  // cost, start_node, count

  dist[A][0] = 0;

  while (!pque.empty()) {
    State now = pque.top();
    pque.pop();

    if (now.cost > dist[now.node][now.count]) continue;

    // 다음 노드로 이동
    for (int i = 0; i < path[now.node].size(); i++) {
      Edge next = path[now.node][i];
      int nextcost = now.cost + next.cost;
      int nextcount = now.count + 1;

      if (nextcount < node + 1 && nextcost < dist[next.node][nextcount]) {
        dist[next.node][nextcount] = nextcost;
        pque.push({nextcost, next.node, nextcount});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> node >> edge >> year;
  cin >> A >> B;  // A: 출발 // B: 도착

  path.resize(node + 1);
  dist.resize(node + 1, vector<int>(node + 1, INT_MAX));

  for (int i = 0; i < edge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    path[from].push_back({to, cost});
    path[to].push_back({from, cost});
  }

  // 첫 dijkstra 실행
  dijkstra();

  int min_cost = INT_MAX;
  for (int i = 0; i < node + 1; i++) {
    if (dist[B][i] < INT_MAX) {
      min_cost = min(min_cost, dist[B][i]);
    }
  }

  cout << min_cost << "\n";

  vector<int> increase(year + 1, 0);

  for (int i = 1; i <= year; i++) {
    int temp;
    cin >> temp;

    increase[i] = increase[i - 1] + temp;

    min_cost = INT_MAX;

    for (int j = 0; j < node + 1; j++) {
      if (dist[B][j] < INT_MAX) {
        min_cost = min(min_cost, dist[B][j] + (j * increase[i]));
      }
    }

    cout << min_cost << "\n";
  }

  return 0;
}