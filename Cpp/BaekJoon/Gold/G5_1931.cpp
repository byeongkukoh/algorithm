#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Time {
  int start;
  int end;
};

bool cmp(Time left, Time right) {
  if (left.end < right.end) return true;
  if (left.end > right.end) return false;

  if (left.start < right.start) return true;
  if (left.start > right.start) return false;

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Time> conf;

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;

    conf.push_back({start, end});
  }

  sort(conf.begin(), conf.end(), cmp);

  int max_cnt = 0;
  int end = 0;

  for (int i = 0; i < n; i++) {
    if (conf[i].start >= end) {
      max_cnt++;
      end = conf[i].end;
    }
  }

  cout << max_cnt;

  return 0;
}

// for (int i = 0; i < n; i++) {
//   int cnt = 1;
//   int idx = i + 1;

//   int end = conf[i].end;

//   while (idx < n) {
//     if (end <= conf[idx].start) {
//       cnt++;
//       end = conf[idx].end;
//     }

//     idx++;
//   }

//   if (cnt > max_cnt) {
//     max_cnt = cnt;
//   }
// }

// cout << max_cnt;

// return 0;