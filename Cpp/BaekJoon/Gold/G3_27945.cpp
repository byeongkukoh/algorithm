#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int u, v, t;

  bool operator<(const Node& other) const {
    if (t != other.t) return t < other.t;

    return false;
  }
};

int find_root(int A, vector<int>& parent) {
  if (parent[A] == A) return A;

  return parent[A] = find_root(parent[A], parent);
}

bool find_union(int A, int B, vector<int>& parent) {
  int x = find_root(A, parent);
  int y = find_root(B, parent);

  if (x == y) return false;

  parent[y] = x;

  return true;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<Node> edges;
  for (int i = 0; i < M; i++) {
    int u, v, t;
    cin >> u >> v >> t;

    edges.push_back({u, v, t});
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(N + 1, -1);
  for (int i = 0; i < N + 1; i++) parent[i] = i;

  int days = 0;

  for (size_t i = 0; i < edges.size(); i++) {
    Node edge = edges[i];

    if (edge.t == days + 1) {
      if (find_union(edge.u, edge.v, parent)) {
        days++;
      } else {
        break;
      }
    } else if (edge.t > days + 1) {
      break;
    }
  }

  cout << days + 1;

  return 0;
}