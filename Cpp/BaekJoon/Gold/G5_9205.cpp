#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int col, row;
};

int dist(const Node& node1, const Node& node2) {
  return abs(node1.row - node2.row) + abs(node1.col - node2.col);
}

string simulation() {
  int n;
  cin >> n;  // 편의점 개수

  Node house = {0, 0};
  cin >> house.col >> house.row;

  vector<Node> conv;
  for (int i = 0; i < n; i++) {
    int tempX, tempY;
    cin >> tempX >> tempY;

    conv.push_back({tempX, tempY});
  }

  Node fest;
  cin >> fest.col >> fest.row;

  queue<Node> que;
  que.push(house);

  vector<bool> visited(n, false);

  while (!que.empty()) {
    Node curr = que.front();
    que.pop();

    if (dist(curr, fest) <= 1000) return "happy";

    for (int i = 0; i < n; i++) {
      Node next = conv[i];

      if (visited[i]) continue;
      if (dist(curr, next) > 1000) continue;

      que.push(next);
      visited[i] = true;
    }
  }

  return "sad";
}

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    cout << simulation() << "\n";
  }

  return 0;
}