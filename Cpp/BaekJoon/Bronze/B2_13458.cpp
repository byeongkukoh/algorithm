#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> people;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    people.push_back(temp);
  }

  int b, c;
  cin >> b >> c;

  long long total_viewer = 0;

  for (int i = 0; i < people.size(); i++) {
    total_viewer += 1;  // 총 감독관

    if (people[i] - b <= 0) continue;

    total_viewer += (people[i] - b) / c;

    if ((people[i] - b) % c != 0) {
      total_viewer += 1;
    }
  }

  cout << total_viewer;

  return 0;
}