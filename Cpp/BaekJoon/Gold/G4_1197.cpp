#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int start, end;
  int weight;

  bool operator<(Node right) const {
    if (weight < right.weight) return true;
    if (weight > right.weight) return false;

    if (start < right.start) return true;
    if (start > right.start) return false;

    if (end < right.end) return true;
    if (end > right.end) return false;

    return false;
  }
};

vector<int> parent;
vector<Node> mst;

int Find(int n) {
  if (parent[n] == n) return n;

  return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
  int rootA = Find(a);
  int rootB = Find(b);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
}

int main() {
  int node, edge;
  cin >> node >> edge;

  parent.resize(node + 1);

  // Union Find 초기화
  for (int i = 0; i < node + 1; i++) {
    parent[i] = i;
  }

  // 데이터 입력
  for (int i = 0; i < edge; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    mst.push_back({from, to, cost});
  }

  // weight 기준 오름차순 정렬
  sort(mst.begin(), mst.end());

  int sum = 0;
  for (int i = 0; i < edge; i++) {
    Node now = mst[i];

    if (Find(now.start) == Find(now.end)) continue;  // 같은 그룹이면 무시

    Union(now.start, now.end);  // 다른 그룹이면 합치기

    sum += now.weight;  // 가중치 누적
  }

  cout << sum;

  return 0;
}