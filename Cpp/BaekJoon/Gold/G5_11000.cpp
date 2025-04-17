#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Time {
  int start;
  int end;

  bool operator<(Time right) const { return end > right.end; }
};

bool cmp(Time left, Time right) {
  if (left.start != right.start) return left.start < right.start;

  return left.end < right.end;
}

int main() {
  int n;
  cin >> n;

  vector<Time> lec;

  for (int i = 0; i < n; i++) {
    int sTime, eTime;
    cin >> sTime >> eTime;

    lec.push_back({sTime, eTime});
  }

  sort(lec.begin(), lec.end(), cmp);

  priority_queue<Time> pque;

  for (int i = 0; i < n; i++) {
    if (pque.empty()) {
      pque.push(lec[i]);
      continue;
    }

    Time qtop = pque.top();

    if (qtop.end <= lec[i].start) {
      pque.pop();
      pque.push(lec[i]);
    } else {
      pque.push(lec[i]);
    }
  }

  cout << pque.size();

  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct Time {
//   long long start;
//   long long end;
// };

// bool cmp(Time left, Time right) {
//   if (left.end < right.end) return true;
//   if (left.end > right.end) return false;

//   if (left.start < right.start) return true;
//   if (left.start > right.start) return false;

//   return false;
// }

// int main() {
//   int n;
//   cin >> n;

//   vector<Time> input;

//   for (int i = 0; i < n; i++) {
//     long long start, end;
//     cin >> start >> end;

//     input.push_back({start, end});
//   }

//   sort(input.begin(), input.end(), cmp);

//   queue<Time> recture;
//   vector<Time> room;

//   for (int i = 0; i < input.size(); i++) {
//     long long start = input[i].start;
//     long long end = input[i].end;

//     recture.push({start, end});
//   }

//   while (!recture.empty()) {
//     long long start = recture.front().start;
//     long long end = recture.front().end;

//     if (room.empty()) {
//       room.push_back({start, end});
//       recture.pop();

//       continue;
//     }

//     int room_cnt = room.size();

//     for (int i = 0; i < room_cnt; i++) {
//       if (room[i].end <= start) {
//         room[i].end = end;
//         recture.pop();
//         break;
//       }
//     }

//     if (start == recture.front().start && end == recture.front().end) {
//       room.push_back({start, end});
//       recture.pop();
//     } else {
//       continue;
//     }
//   }

//   cout << room.size();

//   return 0;
// }