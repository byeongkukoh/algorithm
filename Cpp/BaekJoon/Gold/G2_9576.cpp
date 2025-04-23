#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int from;
  int to;
  int gap;
};

bool cmp(Node left, Node right) {
  if (left.to != right.to) return left.to < right.to;
  if (left.gap != right.gap) return left.gap < right.gap;

  return false;
}

int main() {
  int test;
  cin >> test;

  for (int tc = 0; tc < test; tc++) {
    int n, m;
    cin >> n >> m;

    vector<int> books(n + 1, 0);

    vector<Node> stud;

    for (int i = 0; i < m; i++) {
      int from, to;
      cin >> from >> to;

      stud.push_back({from, to, to - from});
    }

    sort(stud.begin(), stud.end(), cmp);

    int count = 0;

    for (int i = 0; i < m; i++) {
      for (int cur = stud[i].from; cur <= stud[i].to; cur++) {
        if (books[cur] == 0) {
          books[cur] = 1;
          count++;
          break;
        }
      }
    }

    cout << count << "\n";
  }

  return 0;
}