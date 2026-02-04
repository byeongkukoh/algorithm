#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Com {
  int com;
  int time;

  bool operator<(const Com& other) const {
    if (time != other.time) return time > other.time;

    return false;
  }
};

struct Path {
  int from;
  int to;
};

int N, M;

vector<vector<Com>> network;
vector<int> timer;
vector<int> prev_path;

void init() {
  cin >> N >> M;

  network.assign(N + 1, vector<Com>());
  timer.assign(N + 1, INT_MAX);
  prev_path.assign(N + 1, -1);

  for (int i = 0; i < M; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    network[from].push_back({to, cost});
    network[to].push_back({from, cost});
  }
}

void dijkstra(int start) {
  priority_queue<Com> pque;
  pque.push({start, 0});

  timer[start] = 0;

  while (!pque.empty()) {
    Com now = pque.top();
    pque.pop();

    if (now.time > timer[now.com]) continue;

    for (size_t i = 0; i < network[now.com].size(); i++) {
      Com next = network[now.com][i];

      if (timer[next.com] <= next.time + timer[now.com]) continue;

      timer[next.com] = next.time + timer[now.com];
      prev_path[next.com] = now.com;
      pque.push({next.com, next.time + timer[now.com]});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 1. 초기화
  init();

  // 2. 최단 경로 탐색
  int super_com = 1;
  dijkstra(super_com);

  // 3. 경로 복기
  vector<Path> path;
  for (int i = N; i > 0; i--) {
    if (prev_path[i] == -1) continue;

    path.push_back({prev_path[i], i});
  }

  // 4. 정답 출력
  cout << path.size() << "\n";
  for (size_t i = 0; i < path.size(); i++) {
    cout << path[i].from << " " << path[i].to << "\n";
  }

  return 0;
}