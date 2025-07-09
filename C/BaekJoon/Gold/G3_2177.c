#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long cost;
  long long cnt;
} COIN;

int comp(const void* left, const void* right) {
  long long x = ((COIN*)left)->cost;
  long long y = ((COIN*)right)->cost;

  if (x < y) return 1;
  if (x > y) return -1;
  return 0;
}

long long checkMin(long long left, long long right) {
  if (left < right) {
    return left;
  } else {
    return right;
  }
}

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  COIN coins[20];

  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &coins[i].cost, &coins[i].cnt);
  }

  qsort((COIN*)coins, N, sizeof(COIN), comp);

  long long ans = 0;

  while (1) {
    long long pay = C;

    // 최저급료에 정확히 맞춰서 지급
    for (int i = 0; i < N; i++) {
      if (pay < coins[i].cost) continue;

      // 사용한 동전 개수
      long long use = checkMin(coins[i].cnt, pay / coins[i].cost);

      // 남은 급료 계산
      pay = pay - (coins[i].cost * use);
      coins[i].cnt = coins[i].cnt - use;
    }

    // 정확히 지급하지 못하는 경우
    if (pay > 0) {
      int overpay = 0;

      for (int i = N - 1; i >= 0; i--) {
        if (coins[i].cnt > 0) {
          coins[i].cnt = coins[i].cnt - 1;
          pay = pay - coins[i].cost;

          overpay = 1;
          break;
        }
      }

      if (overpay != 1) break;
    }

    ans = ans + 1;
  }

  printf("%lld", ans);

  return 0;
}