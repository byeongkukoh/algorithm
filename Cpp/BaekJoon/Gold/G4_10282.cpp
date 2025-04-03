#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int dist;

  bool operator<(Node right) const { return dist > right.dist; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    vector<vector<Node>> comp;
    vector<int> visited;

    int node, edge, start;
    cin >> node >> edge >> start;

    comp.resize(node + 1);
    visited.assign(node + 1, INT_MAX);

    for (int i = 0; i < edge; i++) {
      int to, from, cost;
      cin >> to >> from >> cost;

      comp[from].push_back({to, cost});
    }

    priority_queue<Node> pque;
    pque.push({start, 0});

    visited[start] = 0;

    while (!pque.empty()) {
      Node now = pque.top();
      pque.pop();

      if (visited[now.node] < now.dist) continue;

      for (int i = 0; i < comp[now.node].size(); i++) {
        Node next = comp[now.node][i];
        int nextdist = visited[now.node] + next.dist;

        if (visited[next.node] <= nextdist) continue;

        pque.push({next.node, nextdist});
        visited[next.node] = nextdist;
      }
    }

    int count = 0;
    int max_time = 0;

    for (int i = 1; i <= node; i++) {
      if (visited[i] != INT_MAX) {
        count++;
        if (max_time < visited[i]) {
          max_time = visited[i];
        }
      }
    }

    cout << count << " " << max_time << "\n";
  }

  return 0;
}