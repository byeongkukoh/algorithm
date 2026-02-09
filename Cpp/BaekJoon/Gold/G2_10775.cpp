#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> gates;

int find(int x) {
  if (gates[x] == x) return x;

  return gates[x] = find(gates[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);

  gates[a] = b;
}

int main() {
  int G, P;
  cin >> G >> P;

  gates.assign(G + 1, 0);

  for (int i = 0; i < G + 1; i++) {
    gates[i] = i;
  }

  int result = 0;

  for (int i = 0; i < P; i++) {
    int now;
    cin >> now;

    now = find(now);

    if (now == 0) break;

    merge(now, now - 1);

    result++;
  }

  cout << result;

  return 0;
}