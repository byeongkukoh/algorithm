#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const {
    if (cost != right.cost) return cost > right.cost;

    return false;
  }
};

int n, m;

vector<vector<Node>> ROOM;

void bfs(int start, vector<int>& dist) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.cost) continue;

    for (size_t i = 0; i < ROOM[now.node].size(); i++) {
      int next = ROOM[now.node][i].node;
      int nextDist = now.cost + ROOM[now.node][i].cost;

      if (dist[next] <= nextDist) continue;

      pque.push({next, nextDist});
      dist[next] = nextDist;
    }
  }
}

int main() {
  int test;
  cin >> test;

  for (int tc = 1; tc <= test; tc++) {
    cin >> n >> m;

    ROOM.clear();
    ROOM.resize(n + 1);

    for (int i = 0; i < m; i++) {
      int from, to, cost;
      cin >> from >> to >> cost;

      ROOM[from].push_back({to, cost});
      ROOM[to].push_back({from, cost});
    }

    int k;
    cin >> k;
    vector<int> att;
    for (int i = 0; i < k; i++) {
      int temp;
      cin >> temp;

      att.push_back(temp);
    }

    int room_number = 0;
    int min_dist = INT_MAX;
    // 1부터 N까지 반복 수행
    for (int i = 1; i <= n; i++) {
      vector<int> dist;
      dist.assign(n + 1, INT_MAX);

      bfs(i, dist);

      int tmp_dist = 0;
      for (int j = 0; j < k; j++) {
        tmp_dist += dist[att[j]];
      }

      if (min_dist > tmp_dist) {
        min_dist = tmp_dist;
        room_number = i;
      }
    }

    cout << room_number << "\n";
  }

  return 0;
}