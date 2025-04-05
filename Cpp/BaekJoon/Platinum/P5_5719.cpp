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

struct Path {
  int start;
  int end;
};

int n, m;
int s, d;  // s : 시작점 / d : 도착점

vector<vector<Node>> map;
vector<int> visited;
vector<vector<int>> parent;
vector<Path> route;
vector<bool> rmVisit = {false};

void dijkstra(int start) {
  visited.assign(n, INT_MAX);

  priority_queue<Node> pque;
  pque.push({start, 0});

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.dist) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];

      if (next.dist == -1) continue;

      int nextdist = now.dist + next.dist;

      if (visited[next.node] < nextdist) continue;

      if (visited[next.node] == nextdist) {
        parent[next.node].push_back(now.node);
      } else {
        visited[next.node] = nextdist;
        parent[next.node].clear();
        parent[next.node].push_back(now.node);
        pque.push({next.node, nextdist});
      }
    }
  }
}

void removePath(int curr) {
  if (curr == s) return;
  if (rmVisit[curr]) return;

  rmVisit[curr] = true;

  for (int i = 0; i < parent[curr].size(); i++) {
    int prev = parent[curr][i];

    for (int i = 0; i < map[prev].size(); i++) {
      if (map[prev][i].node == curr) {
        map[prev][i].dist = -1;
      }
    }

    removePath(prev);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (1) {
    cin >> n >> m;

    if (n == 0 && m == 0) break;

    cin >> s >> d;

    map.assign(n, vector<Node>());
    parent.assign(n, vector<int>());
    // route.clear();

    for (int i = 0; i < m; i++) {
      int from, to, dist;
      cin >> from >> to >> dist;

      map[from].push_back({to, dist});
    }

    dijkstra(s);

    // 경로 역추적 및 제거
    rmVisit.assign(n, false);
    removePath(d);

    parent.assign(n, vector<int>());
    dijkstra(s);

    if (visited[d] == INT_MAX) {
      cout << -1 << "\n";
    } else {
      cout << visited[d] << "\n";
    }
  }

  return 0;
}

// ===========
// 아래 코드는 시간 초과 발생

// #include <climits>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct Node {
//   int node;
//   int dist;

//   bool operator<(Node right) const { return dist > right.dist; }
// };

// struct Path {
//   int start;
//   int end;
// };

// int n, m;
// int s, d;  // s : 시작점 / d : 도착점

// vector<vector<Node>> map;
// vector<int> visited;
// vector<int> path;
// vector<Path> route;

// void dijkstra(int start) {
//   visited.assign(n, INT_MAX);
//   path.assign(n, -1);

//   priority_queue<Node> pque;
//   pque.push({start, 0});

//   while (!pque.empty()) {
//     Node now = pque.top();
//     pque.pop();

//     if (visited[now.node] < now.dist) continue;

//     for (int i = 0; i < map[now.node].size(); i++) {
//       Node next = map[now.node][i];

//       if (next.dist == 0) continue;

//       int nextdist = now.dist + next.dist;

//       if (visited[next.node] <= nextdist) continue;

//       visited[next.node] = nextdist;
//       path[next.node] = now.node;
//       pque.push({next.node, nextdist});
//     }
//   }
// }

// int main() {
//   while (1) {
//     cin >> n >> m;

//     if (n == 0 && m == 0) break;

//     cin >> s >> d;

//     map.assign(n, vector<Node>());
//     route.clear();

//     for (int i = 0; i < m; i++) {
//       int from, to, dist;
//       cin >> from >> to >> dist;

//       map[from].push_back({to, dist});
//     }

//     dijkstra(s);
//     int min_dist = visited[d];  // 최단 경로

//     for (int i = d; i != s; i = path[i]) {
//       route.push_back({path[i], i});

//       for (int j = 0; j < map[path[i]].size(); j++) {
//         if (map[path[i]][j].node == i) {
//           map[path[i]][j].dist = 0;
//         }
//       }
//     }

//     while (1) {
//       dijkstra(s);

//       if (min_dist == visited[d]) {
//         for (int i = d; i != s; i = path[i]) {
//           for (int j = 0; j < map[path[i]].size(); j++) {
//             if (map[path[i]][j].node == i) {
//               map[path[i]][j].dist = 0;
//             }
//           }
//         }
//       } else {
//         if (visited[d] == INT_MAX) {
//           cout << -1 << "\n";
//         } else {
//           cout << visited[d] << "\n";
//         }
//         break;
//       }
//     }
//   }

//   return 0;
// }