#include <iostream>
#include <vector>

using namespace std;

struct Sch {
  int time;
  int price;
};

int total_price = 0;
vector<Sch> schedule;

void func(int now, int sum, int n) {
  if (now == n) {
    total_price = max(total_price, sum);

    return;
  }

  if (now > n) return;

  // now를 선택하는 경우
  if (now + schedule[now].time <= n) {
    func(now + schedule[now].time, sum + schedule[now].price, n);
  }

  // now를 선택하지 않는 경우
  func(now + 1, sum, n);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int time, price;
    cin >> time >> price;

    schedule.push_back({time, price});
  }

  func(0, 0, n);

  cout << total_price;

  return 0;
}