#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Data {
  int price;
  int day;

  bool operator<(Data right) const {
    if (price > right.price) return true;

    return false;
  }
};

bool cmp(Data left, Data right) {
  if (left.day < right.day) return true;

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Data> data;
  priority_queue<Data> choice;

  data.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> data[i].price >> data[i].day;
  }

  sort(data.begin(), data.end(), cmp);

  for (int i = 0; i < n; i++) {
    choice.push(data[i]);

    if (choice.size() > data[i].day) {
      choice.pop();
    }
  }

  int result = 0;
  while (!choice.empty()) {
    Data curr = choice.top();
    choice.pop();

    result += curr.price;
  }

  cout << result;

  return 0;
}