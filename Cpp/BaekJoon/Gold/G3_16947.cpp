#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

vector<bool> cycle;           // 순환역 확인
vector<int> dist;             // 순환역까지 거리
vector<vector<int>> station;  // 역 그래프

int main() {
  cin >> n;

  cycle.resize(n + 1, true);
  dist.resize(n + 1, INT_MAX);

  station.resize(n + 1);

  for (int i = 0; i < n; i++) {
    int from, to;
    cin >> from >> to;

    station[from].push_back(to);
    station[to].push_back(from);
  }

  // 순환 정점 확인
  // 잎(1차수) 제거 기법으로 순환 정점 확인
  vector<int> deg(n + 1, 0);
  for (int i = 1; i <= n; i++) deg[i] = (int)station[i].size();

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) que.push(i);
  }

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    cycle[now] = false;

    for (size_t i = 0; i < station[now].size(); i++) {
      int next = station[now][i];
      if (!cycle[next]) continue;

      deg[next]--;

      if (deg[next] == 1) que.push(next);
    }
  }

  // 순환역으로부터 최단 거리 구하기
  // BFS 시작점
  queue<int> bque;

  for (int i = 1; i <= n; i++) {
    if (cycle[i]) {
      dist[i] = 0;
      bque.push(i);  // Queue에 순환역 넣고 시작
    }
  }

  while (!bque.empty()) {
    int now = bque.front();
    bque.pop();

    for (size_t i = 0; i < station[now].size(); i++) {
      int next = station[now][i];

      if (dist[next] != INT_MAX) continue;

      dist[next] = dist[now] + 1;
      bque.push(next);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }

  return 0;
}