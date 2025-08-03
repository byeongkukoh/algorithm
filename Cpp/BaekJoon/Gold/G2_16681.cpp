#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  long long dist;

  bool operator<(Node right) const {
    if (dist != right.dist) return dist > right.dist;

    return false;
  }
};

int N, M, D, E;

vector<vector<Node>> road;
vector<long long> toPeak;  // 정상까지 거리 (집 -> 정상)
vector<long long>
    toUniv;  // 학교까지 거리 (정상 -> 학교 // 실제 코드에서는 학교 -> 정상)
vector<int> height;  // 각 정점의 높이

void bfs(int start, vector<long long>& dist) {
  priority_queue<Node> pque;
  pque.push({start, 0});

  dist[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (size_t i = 0; i < road[now.node].size(); i++) {
      int next = road[now.node][i].node;
      long long nextDist = now.dist + road[now.node][i].dist;

      if (height[now.node] >= height[next]) continue;
      if (dist[next] <= nextDist) continue;

      pque.push({next, nextDist});
      dist[next] = nextDist;
    }
  }
}

int main() {
  cin >> N >> M >> D >> E;

  road.resize(N + 1);
  toPeak.resize(N + 1, LLONG_MAX);
  toUniv.resize(N + 1, LLONG_MAX);
  height.resize(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    cin >> height[i];
  }

  for (int i = 0; i < M; i++) {
    int from, to, dist;
    cin >> from >> to >> dist;

    road[from].push_back({to, dist});
    road[to].push_back({from, dist});
  }

  // 집 -> 정상 bfs
  bfs(1, toPeak);

  // 학교 -> 정상 bfs
  bfs(N, toUniv);

  long long result = LLONG_MIN;

  for (int i = 2; i < N; i++) {
    if (toPeak[i] == LLONG_MAX || toUniv[i] == LLONG_MAX) continue;

    // 가치 = 성취도(hE) - 소모 체력(dist * D)
    long long value = (height[i] * E) - ((toPeak[i] * D) + (toUniv[i] * D));

    if (result < value) result = value;
  }

  if (result == LLONG_MIN) {
    cout << "Impossible";
  } else {
    cout << result;
  }

  return 0;
}