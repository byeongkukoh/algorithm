#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct NODE {
  int node;
  int weight;

  bool operator<(NODE right) const {
    if (weight != right.weight) return weight < right.weight;

    return false;
  }
};

vector<vector<NODE>> brg;
vector<int> weight;

int n, m;

void bfs(int start) {
  priority_queue<NODE> pque;
  pque.push({start, 0});

  weight[start] = INT_MAX;

  while (!pque.empty()) {
    NODE now = pque.top();
    pque.pop();

    if (now.weight < weight[now.node] && now.node != start) continue;

    for (int i = 0; i < brg[now.node].size(); i++) {
      int next = brg[now.node][i].node;
      int nextWeight = brg[now.node][i].weight;

      int possibleWeight = min(nextWeight, weight[now.node]);

      if (possibleWeight <= weight[next]) continue;

      pque.push({next, possibleWeight});
      weight[next] = possibleWeight;
    }
  }
}

int main() {
  cin >> n >> m;

  brg.resize(n + 1);
  weight.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int from, to, w;
    cin >> from >> to >> w;

    brg[from].push_back({to, w});
    brg[to].push_back({from, w});
  }

  int start, end;
  cin >> start >> end;

  bfs(start);

  cout << weight[end];

  return 0;
}