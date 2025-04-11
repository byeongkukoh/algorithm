#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int cost;

  bool operator<(Node right) const { return cost > right.cost; }
};

struct Prod {
  int id;
  int rev;
  int dest;
  int profit;

  bool operator<(Prod right) const {
    if (profit != right.profit)
      return profit < right.profit;
    else
      return id > right.id;
  }
};

int n, m;  // n : 정점수 & m : 간선 수

vector<vector<Node>> map;
vector<int> visited;
vector<Prod> temp;
bool isRemove[30001];
bool isCreate[30001];

priority_queue<Prod> products;

void init();
void addProduct();
void rmProduct(int id);
void dijkstra(int start);

int main() {
  int Q;
  cin >> Q;  // 명령어 개수

  for (int q = 0; q < Q; q++) {
    int comm;
    cin >> comm;

    if (comm == 100) {  // 값 입력
      init();
    } else if (comm == 200) {  // 여행 상품 추가
      addProduct();
    } else if (comm == 300) {
      int id;
      cin >> id;

      if (!isCreate[id]) {
        continue;
      } else {
        isRemove[id] = true;
      }
    } else if (comm == 400) {
      bool sold = false;

      while (!products.empty()) {
        Prod now = products.top();

        if (isRemove[now.id]) {
          products.pop();
          continue;
        }

        if (now.profit < 0) {
          break;  // 판매 불가
        } else {
          cout << now.id << "\n";
          products.pop();
          sold = true;
          break;
        }
      }

      if (!sold) {
        cout << -1 << "\n";
      }
    } else if (comm == 500) {
      int start;
      cin >> start;

      dijkstra(start);

      temp.clear();
      while (!products.empty()) {
        Prod now = products.top();
        products.pop();

        if (isRemove[now.id]) continue;

        if (visited[now.dest] == INT_MAX) {
          now.profit = -100;
        } else {
          now.profit = now.rev - visited[now.dest];
        }

        temp.push_back(now);
      }

      for (int i = 0; i < temp.size(); i++) {
        products.push({temp[i]});
      }
      temp.clear();
    }
  }
  return 0;
}

void dijkstra(int start) {
  visited.assign(n, INT_MAX);

  priority_queue<Node> pque;
  pque.push({start, 0});

  visited[start] = 0;

  while (!pque.empty()) {
    Node now = pque.top();
    pque.pop();

    if (visited[now.node] < now.cost) continue;

    for (int i = 0; i < map[now.node].size(); i++) {
      Node next = map[now.node][i];
      int nextCost = now.cost + next.cost;

      if (visited[next.node] <= nextCost) continue;

      visited[next.node] = nextCost;
      pque.push({next.node, nextCost});
    }
  }
}

void init() {
  cin >> n >> m;

  map.clear();
  map.resize(n);
  visited.assign(n, INT_MAX);

  fill(isCreate, isCreate + 30000, false);
  fill(isRemove, isRemove + 30000, false);

  while (!products.empty()) products.pop();  // 이전 상품들 제거

  for (int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;

    map[from].push_back({to, cost});
    map[to].push_back({from, cost});
  }

  dijkstra(0);
}

void addProduct() {
  int id, rev, dest, profit;
  cin >> id >> rev >> dest;

  isCreate[id] = true;

  if (visited[dest] == INT_MAX) {
    profit = -100;
  } else {
    profit = rev - visited[dest];
  }

  products.push({id, rev, dest, profit});
}

void rmProduct(int id) {
  temp.clear();

  while (!products.empty()) {
    Prod now = products.top();
    products.pop();

    if (now.id == id) continue;

    temp.push_back(now);
  }

  for (int i = 0; i < temp.size(); i++) {
    products.push(temp[i]);
  }

  temp.clear();
}