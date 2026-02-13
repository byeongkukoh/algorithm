#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Meat {
  int weight;
  int price;

  bool operator<(const Meat& other) const {
    if (price != other.price) return price < other.price;
    if (weight != other.weight) return weight > other.weight;

    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<Meat> info;

  for (int i = 0; i < N; i++) {
    int w, p;
    cin >> w >> p;

    info.push_back({w, p});
  }

  sort(info.begin(), info.end());

  int sum_weight = 0;
  int total_price = 0;
  int prev_price = 0;
  long long result = LLONG_MAX;

  for (int i = 0; i < N; i++) {
    if (prev_price == info[i].price) {
      total_price += info[i].price;
      sum_weight += info[i].weight;
    } else {
      prev_price = info[i].price;
      total_price = info[i].price;
      sum_weight += info[i].weight;
    }

    if (sum_weight >= M) {
      result = min(result, (long long)total_price);
    }
  }

  if (result == LLONG_MAX) {
    cout << -1;
  } else {
    cout << result;
  }

  return 0;
}