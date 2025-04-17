#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Product {
  int name;
  int* num;

  bool operator<(Product right) const { return *num > *right.num; }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> name;
  int dat[101] = {0};
  bool check[101] = {false};

  for (int _ = 0; _ < k; _++) {
    int temp;
    cin >> temp;

    name.push_back(temp);
    dat[temp]++;
  }

  priority_queue<Product> prod;

  int result = 0;

  for (int i = 0; i < k; i++) {
    if (prod.size() < n && check[name[i]] != true) {
      dat[name[i]]--;
      prod.push({name[i], &dat[name[i]]});
      check[name[i]] = true;
      continue;
    }

    if (check[name[i]] != true) {
      Product now = prod.top();
      prod.pop();
      check[now.name] = false;
      result++;
      dat[name[i]]--;
      check[name[i]] = true;
      prod.push({name[i], &dat[name[i]]});
    } else {
      dat[name[i]]--;
    }
  }

  cout << result;

  return 0;
}