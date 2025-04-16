#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Dia {
  int weight;
  int cost;
};

bool cmp(Dia left, Dia right) { return left.weight < right.weight; }

int main() {
  int n, k;
  cin >> n >> k;

  vector<Dia> jewels;
  vector<int> bags;

  jewels.resize(n);
  bags.resize(k);

  for (int i = 0; i < n; i++) {
    cin >> jewels[i].weight >> jewels[i].cost;
  }

  for (int i = 0; i < k; i++) {
    cin >> bags[i];
  }

  sort(jewels.begin(), jewels.end(), cmp);
  sort(bags.begin(), bags.end());

  priority_queue<int> pque;
  long long result = 0;
  int idx = 0;

  for (int i = 0; i < k; i++) {
    int bag_weight = bags[i];

    while (idx < n && jewels[idx].weight <= bag_weight) {
      pque.push(jewels[idx].cost);
      idx++;
    }

    if (!pque.empty()) {
      result += pque.top();
      pque.pop();
    }
  }

  cout << result;

  return 0;
}