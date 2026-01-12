#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int start;
  int end;
  long long cost;

  bool operator<(const Node& others) const {
    if (cost != others.cost) return cost < others.cost;

    return false;
  }
};

int find_root(int node, vector<int>& parent) {
  if (parent[node] == node) return node;

  return parent[node] = find_root(parent[node], parent);
}

void union_group(int node1, int node2, vector<int>& parent) {
  int rootA = find_root(node1, parent);
  int rootB = find_root(node2, parent);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
}

int main() {
  int N, M;
  cin >> N >> M;

  // 간선 입력
  vector<Node> vill;
  for (int i = 0; i < M; i++) {
    int tStart, tEnd, tCost;
    cin >> tStart >> tEnd >> tCost;

    vill.push_back({tStart, tEnd, tCost});
  }

  sort(vill.begin(), vill.end());

  // 부모 배열 초기화
  vector<int> parent(N + 1, -1);
  for (int i = 0; i < N + 1; i++) {
    parent[i] = i;
  }

  // MST (최소 스패닝 트리)
  long long min_path_cost = 0;
  long long max_cost =
      INT_MIN;  // 마을 두 개로 나눌 때 가장 경로 값이 큰 애로 분리
  for (int i = 0; i < M; i++) {
    // 같은 그룹이면 무시 (싸이클 생성되면 무시)
    if (find_root(vill[i].start, parent) == find_root(vill[i].end, parent))
      continue;

    // 다른 그룹이면 합치기
    union_group(vill[i].start, vill[i].end, parent);

    min_path_cost += vill[i].cost;

    max_cost = max(max_cost, vill[i].cost);
  }

  cout << min_path_cost - max_cost;

  return 0;
}