// 1. 맥세권: 맥도날드와 집 사이의 최단거리가 X 이하
// 2. 스세권: 스타벅스와 집 사이의 최단거리가 Y 이하
// 3. 맥세권과 스세권을 만족하는 집 중, 최단거리 합이 최소인 집

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

int V, E;

vector<vector<Node>> map;  // 지도
vector<long long> mdist;   // 맥세권 거리
vector<long long> sdist;   // 스세권 거리

priority_queue<Node> pque;  // 다익스트라 큐

void bfs(vector<long long>& dist, int d) {
  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (dist[now.node] < now.dist) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      long long nextDist = now.dist + next.dist;

      if (nextDist > d) continue;
      if (dist[next.node] <= nextDist) continue;

      pque.push({next.node, nextDist});
      dist[next.node] = nextDist;
    }
  }
}

int main() {
  cin >> V >> E;

  map.resize(V + 1);  // 1번 노드부터 시작 (1 ~ V)
  sdist.resize(V + 1, LLONG_MAX);
  mdist.resize(V + 1, LLONG_MAX);

  for (int i = 0; i < E; i++) {
    int from, to, dist;
    cin >> from >> to >> dist;

    map[from].push_back({to, dist});
    map[to].push_back({from, dist});
  }

  // 맥세권 조건
  int M, x;
  cin >> M >> x;
  for (int i = 0; i < M; i++) {
    // 큐에 맥도날드 정점 추가
    int temp;
    cin >> temp;
    pque.push({temp, 0});
    mdist[temp] = 0;
  }

  // 맥세권 다익스트라 실행
  bfs(mdist, x);

  // 큐 비우기
  while (!pque.empty()) pque.pop();

  // 스세권 조건
  int S, y;
  cin >> S >> y;
  for (int i = 0; i < S; i++) {
    // 큐에 스타벅스 정점 추가
    int temp;
    cin >> temp;
    pque.push({temp, 0});
    sdist[temp] = 0;
  }

  // 스세권 다익스트라 실행
  bfs(sdist, y);

  // 최단거리 체크
  int res = -1;

  // Debugging Code
  // for (int i = 1; i <= V; i++) cout << mdist[i] << " ";
  // cout << "\n";
  // for (int i = 1; i <= V; i++) cout << sdist[i] << " ";
  // cout << "\n";
  // ==============

  for (int i = 1; i <= V; i++) {
    // 스타벅스 or 맥도날드 정점은 집 X
    if (mdist[i] == 0 || sdist[i] == 0) continue;
    // 스타벅스 or 맥도날드에서 도달할 수 없는 정점
    if (mdist[i] == LLONG_MAX || sdist[i] == LLONG_MAX) continue;

    int dist = mdist[i] + sdist[i];

    if (res == -1 || res > dist) res = dist;
  }

  cout << res;

  return 0;
}