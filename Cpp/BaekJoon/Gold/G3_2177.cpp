#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Coins {
  long long cost;
  long long cnt;
};

bool comp(const Coins& left, const Coins& right) {
  if (left.cost != right.cost) return left.cost > right.cost;

  return false;
}

int main() {
  int N;
  long long C;

  cin >> N >> C;

  vector<Coins> coins;
  coins.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> coins[i].cost >> coins[i].cnt;
  }

  sort(coins.begin(), coins.end(), comp);

  long long ans = 0;

  while (true) {
    long long pay = C;

    // 최저급료에 정확히 맞춰서 지급
    for (int i = 0; i < N; i++) {
      if (pay < coins[i].cost) continue;

      // 사용한 동전의 개수
      long long use = min(coins[i].cnt, pay / coins[i].cost);

      // 남은 급료 및 현금 개수
      pay = pay - (coins[i].cost * use);
      coins[i].cnt = coins[i].cnt - use;
    }

    // 정확히 지급하지 못하는 경우 초과 지급 계산
    if (pay > 0) {
      bool overpay = false;

      for (int i = N - 1; i >= 0; i--) {
        if (coins[i].cnt > 0) {
          coins[i].cnt = coins[i].cnt - 1;
          pay = pay - coins[i].cost;
          overpay = true;

          break;
        }
      }

      if (!overpay) break;
    }

    ans++;
  }

  cout << ans;

  return 0;
}