#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Lecture {
  int num;
  int start;
  int end;
};

struct Time {
  int start;
  int end;

  bool operator<(Time right) const {
    if (end != right.end) return end > right.end;

    return false;
  }
};

bool cmp(Lecture left, Lecture right) {
  if (left.start != right.start) return left.start < right.start;

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Lecture> lec;

  for (int i = 0; i < n; i++) {
    int num, from, to;
    cin >> num >> from >> to;

    lec.push_back({num, from, to});
  }

  sort(lec.begin(), lec.end(), cmp);

  priority_queue<Time> pque;

  for (int i = 0; i < n; i++) {
    Lecture now = lec[i];

    if (pque.empty())
      pque.push({now.start, now.end});
    else {
      if (pque.top().end <= now.start) {
        pque.pop();
        pque.push({now.start, now.end});
      } else {
        pque.push({now.start, now.end});
      }
    }
  }

  cout << pque.size();

  return 0;
}