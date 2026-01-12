#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
  long long cost;
} Node;

int compare(const void* a, const void* b) {
  const Node* n1 = (const Node*)a;
  const Node* n2 = (const Node*)b;

  // 오름차순 정렬
  if (n1->cost < n2->cost) {
    return -1;  // 작으면 앞으로 이동 (음수 리턴)
  } else if (n1->cost > n2->cost) {
    return 1;  // 크면 뒤로 이동 (양수 리턴)
  } else {
    return 0;  // 같음
  }
}

int find_root(int node, int* parent) {
  if (parent[node] == node) return node;

  return parent[node] = find_root(parent[node], parent);
}

void union_group(int node1, int node2, int* parent) {
  int rootA = find_root(node1, parent);
  int rootB = find_root(node2, parent);

  if (rootA == rootB) return;

  parent[rootB] = rootA;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  Node* vill = (Node*)malloc(sizeof(Node) * M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %lld", &vill[i].start, &vill[i].end, &vill[i].cost);
  }

  // 비용 순으로 낮은 것부터 정렬
  qsort(vill, M, sizeof(Node), compare);

  // parent 선언 및 초기화
  int* parent = (int*)malloc(sizeof(int) * (N + 1));
  for (int i = 0; i < N + 1; i++) {
    parent[i] = i;
  }

  // MST
  long long min_path_cost = 0;
  long long max_cost = 0;
  for (int i = 0; i < M; i++) {
    if (find_root(vill[i].start, parent) == find_root(vill[i].end, parent))
      continue;

    union_group(vill[i].start, vill[i].end, parent);

    min_path_cost += vill[i].cost;

    if (max_cost < vill[i].cost) max_cost = vill[i].cost;
  }

  printf("%lld", min_path_cost - max_cost);

  return 0;
}