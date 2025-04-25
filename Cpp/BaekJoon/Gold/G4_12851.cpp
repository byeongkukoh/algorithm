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

int n, k;

int dx[] = {-1, 1, 2};

vector<int> dist(200000, INT_MAX);
vector<int> counting(200000, 0);

void dijkstra(Node start) {
  priority_queue<Node> pque;
  pque.push({start});

  dist[start.node] = 0;
  counting[start.node] = 1;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    for (int i = 0; i < 3; i++) {
      int nextNode;
      if (i == 2) {
        nextNode = now.node * dx[i];
      } else {
        nextNode = now.node + dx[i];
      }

      int nextdist = now.dist + 1;

      if (nextNode < 0 || nextNode >= 200000) continue;
      if (dist[nextNode] < nextdist) continue;

      if (dist[nextNode] == nextdist) {
        counting[nextNode] += counting[now.node];
        continue;
      }

      dist[nextNode] = nextdist;
      counting[nextNode] = counting[now.node];

      pque.push({nextNode, nextdist});
    }
  }
}

int main() {
  cin >> n >> k;

  dijkstra({n, 0});

  cout << dist[k] << "\n";
  cout << counting[k] << "\n";

  return 0;
}