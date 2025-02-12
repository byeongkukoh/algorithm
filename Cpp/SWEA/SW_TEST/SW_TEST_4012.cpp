#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> score;
vector<int> path;
vector<int> used;
vector<int> res;
int N;

void init(int N) {
  score.clear();
  score.resize(N, vector<int>(N, 0));

  used.clear();
  used.resize(N + 1, 0);

  path.clear();
  path.resize(N, 0);

  res.clear();
}

void func(int now) {
  if (now == N / 2) {
    int sum = 0;
    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        sum += score[path[i] - 1][path[j] - 1];
      }
    }
    res.push_back(sum);

    return;
  }

  for (int i = 1; i <= N; i++) {
    if (used[i] == 1) continue;
    if (now > 0 && path[now - 1] > i) continue;
    path[now] = i;
    used[i] = 1;

    func(now + 1);

    path[now] = 0;
    used[i] = 0;
  }
}

int main() {
  int test;
  cin >> test;
  for (int t = 0; t < test; t++) {
    cin >> N;

    init(N);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> score[i][j];
      }
    }

    func(0);

    int min = INT_MAX;
    for (int i = 0; i < res.size() / 2; i++) {
      int temp = res[i] - res[res.size() - 1 - i];

      if (temp < 0) temp = -temp;

      if (temp < min) {
        min = temp;
      }
    }

    cout << "#" << t + 1 << " " << min << "\n";
  }

  return 0;
}