#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, b;
  cin >> n >> m >> b;

  vector<int> blocks;
  blocks.resize(n * m, 0);

  int min_val = 256;
  int max_val = 0;

  for (int i = 0; i < n * m; i++) {
    cin >> blocks[i];

    if (blocks[i] < min_val) min_val = blocks[i];

    if (blocks[i] > max_val) max_val = blocks[i];
  }

  int height = 0;
  int sTime = 100000000;

  for (int target = max_val; target >= min_val; target--) {
    int del_block = 0;
    int ins_block = 0;
    int need_time = 0;

    for (int i = 0; i < n * m; i++) {
      if (blocks[i] > target) {
        need_time += (blocks[i] - target) * 2;
        del_block += (blocks[i] - target);
      } else {
        need_time += (target - blocks[i]) * 1;
        ins_block += (target - blocks[i]);
      }
    }

    if (del_block + b - ins_block < 0) continue;

    if (need_time < sTime) {
      sTime = need_time;
      height = target;
    }
  }

  cout << sTime << " " << height;

  return 0;
}