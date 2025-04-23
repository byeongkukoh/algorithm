#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int from;
  int to;
};

bool cmp(Node a, Node b) {
  if (a.from != b.from) return a.from < b.from;

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<Node> lines;

  for (int i = 0; i < n; i++) {
    int from, to;
    cin >> from >> to;

    lines.push_back({from, to});
  }

  sort(lines.begin(), lines.end(), cmp);

  int sum = 0;
  int cur = lines[0].from;
  for (int i = 0; i < n; i++) {
    if (cur < lines[i].to) {
      sum += lines[i].to - cur;
      cur = lines[i].to;
    }

    if (i == n - 1) break;

    if (cur < lines[i + 1].from) {
      cur = lines[i + 1].from;
    }
  }

  cout << sum;

  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct Node {
//   int from;
//   int to;

//   bool operator<(Node right) const {
//     if (from != right.from) return from > right.from;

//     return false;
//   }
// };

// int main() {
//   ios_base ::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int n;
//   cin >> n;

//   priority_queue<Node> lines;

//   for (int i = 0; i < n; i++) {
//     int from, to;
//     cin >> from >> to;

//     lines.push({from, to});
//   }

//   int sum = 0;
//   int cur = lines.top().from;

//   int idx = 0;
//   while (1) {
//     Node line = lines.top();
//     lines.pop();

//     if (cur < line.to) {
//       sum += line.to - cur;
//       cur = line.to;
//     }

//     if (idx == n - 1) break;

//     line = lines.top();

//     if (cur < line.from) {
//       cur = line.from;
//     }

//     idx++;
//   }

//   cout << sum;

//   return 0;
// }