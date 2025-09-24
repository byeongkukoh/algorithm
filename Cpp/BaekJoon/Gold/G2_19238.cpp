#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TAXI {
  int row;
  int col;
};

struct Node {
  int y;
  int x;
  int dist;
};

struct Node2 {
  int idx;
  int y;
  int x;
  int dist;

  bool operator<(Node2 right) const {
    if (dist != right.dist) return dist > right.dist;
    if (y != right.y) return y > right.y;
    return x > right.x;
  }
};

struct Point {
  int start_y = 0;
  int start_x = 0;
  int dest_y = 0;
  int dest_x = 0;
  bool check = false;
};

int N, M, fuel;

vector<Point> people;
vector<vector<int>> MAP;
vector<vector<int>> dist;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(TAXI start) {
  dist.assign(N + 1, vector<int>(N + 1, INT_MAX));

  queue<Node> que;
  que.push({start.row, start.col, 0});

  dist[start.row][start.col] = 0;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
      if (MAP[ny][nx] == 1) continue;
      if (dist[ny][nx] <= now.dist + 1) continue;

      que.push({ny, nx, now.dist + 1});
      dist[ny][nx] = now.dist + 1;
    }
  }
}

void simulator(TAXI taxi) {
  size_t remainPeople = people.size();

  while (remainPeople != 0) {
    bfs(taxi);

    priority_queue<Node2> pque;
    for (int i = 0; i < M; i++) {
      Point temp = people[i];

      if (temp.check) continue;
      if (dist[temp.start_y][temp.start_x] == INT_MAX) continue;

      pque.push(
          {i, temp.start_y, temp.start_x, dist[temp.start_y][temp.start_x]});
    }

    // 갈 수 있는 손님이 없는 경우
    if (pque.empty()) {
      cout << -1;
      return;
    }

    // 손님까지 거리가 연료보다 큰 경우
    Node2 target = pque.top();
    if (target.dist > fuel) {
      cout << -1;
      return;
    }

    fuel -= target.dist;
    taxi = {target.y, target.x};
    bfs(taxi);

    // 목표 지점까지 거리가 연료보다 큰 경우
    int nowDist = dist[people[target.idx].dest_y][people[target.idx].dest_x];
    if (nowDist > fuel) {
      cout << -1;
      return;
    }

    fuel -= nowDist;
    taxi = {people[target.idx].dest_y, people[target.idx].dest_x};
    fuel += nowDist * 2;

    people[target.idx].check = true;
    remainPeople--;
  }

  cout << fuel;
  return;
}

int main() {
  // 초기 값 입력
  cin >> N >> M >> fuel;

  // 맵 정보 입력
  MAP.resize(N + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> MAP[i][j];
    }
  }

  // 택시 시작 위치
  TAXI taxi;
  cin >> taxi.row >> taxi.col;

  // 시작지 & 목적지
  people.resize(M);
  for (int i = 0; i < M; i++) {
    Point temp;
    cin >> temp.start_y >> temp.start_x >> temp.dest_y >> temp.dest_x;

    people[i] = temp;
  }

  simulator(taxi);

  return 0;
}