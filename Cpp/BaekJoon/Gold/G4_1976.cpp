// BFS 풀이
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> visited;

void bfs(int start) {
  queue<int> que;
  que.push(start);

  visited[start] = 1;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int i = 1; i < map[now].size(); i++) {
      if (map[now][i] == 0) continue;

      int next = i;

      if (visited[next] == 1) continue;

      visited[next] = 1;
      que.push(next);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  map.resize(n + 1, vector<int>(n + 1, 0));
  visited.resize(n + 1, 0);

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      cin >> map[i][j];
    }
  }

  vector<int> plan;

  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;

    plan.push_back(temp);
  }

  bfs(plan[0]);

  for (int i = 0; i < m; i++) {
    if (visited[plan[i]] != 1) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}

// Union-Find 풀이
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// vector<int> parent;

// int Find(int n) {
//   // 대표가 자기 자신이면 반환
//   if (n == parent[n]) return n;

//   // root까지 갱신
//   parent[n] = Find(parent[n]);

//   return parent[n];
// }

// // 그룹 병합
// void Union(int A, int B) {
//   int rootA = Find(A);
//   int rootB = Find(B);

//   if (rootA == rootB) return;

//   parent[rootB] = rootA;
// }

// int main() {
//   int n, m;
//   cin >> n >> m;

//   parent.resize(n + 1, 0);
//   for (int i = 1; i < n + 1; i++) {
//     parent[i] = i;
//   }

//   for (int i = 1; i < n + 1; i++) {
//     for (int j = 1; j < n + 1; j++) {
//       int temp;
//       cin >> temp;

//       if (temp == 1) {
//         Union(i, j);
//       }
//     }
//   }

//   int root = -1;
//   for (int i = 0; i < m; i++) {
//     int temp;
//     cin >> temp;

//     int temp_root = Find(temp);

//     if (root != -1 && root == temp_root)
//       continue;
//     else if (root == -1) {
//       root = temp_root;
//     } else {
//       cout << "NO";
//       return 0;
//     }
//   }

//   cout << "YES";

//   return 0;
// }