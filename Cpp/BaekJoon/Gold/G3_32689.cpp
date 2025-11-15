#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int clockwise_dist(int n, int a, int b) {
  if (a < b) {
    return b - a;
  } else {
    return n - a + b;
  }
}

int main() {
  int n;
  cin >> n;

  // 트랙 정보 입력
  vector<int> track(n);
  deque<int> dque;  // 쓰레기가 있는 트랙 인덱스만 저장
  for (int i = 0; i < n; i++) {
    cin >> track[i];

    if (track[i] != 0) {
      dque.push_back(i);
    }
  }

  long long dist = 0;  // 총 이동거리
  int pos = 0;         // 시작 위치
  int dir = 0;         // 이동 방향 (0: 시계방향, 1: 반시계방향)

  while (!dque.empty()) {
    int left = dque.front();
    int right = dque.back();

    int next_idx = left;  // 먼저 만나는 구역
    int far_idx = right;  // 나중에 만나는 구역
    if (dir == 1) {       // 반시계 방향이면 반대로
      next_idx = right;
      far_idx = left;
    }

    // 쓰레기가 한 곳만 남은 경우
    if (next_idx == far_idx) {
      int idx = next_idx;

      if (dir == 0) {
        dist += clockwise_dist(n, pos, idx);
      } else {
        dist += clockwise_dist(n, idx, pos);
      }

      if (track[idx] > 0) {
        dist += 1LL * (track[idx] - 1) * n;
      }

      break;
    }

    // 쓰레기가 두 곳 이상 남은 경우
    if (dir == 0) {
      dist += clockwise_dist(n, pos, next_idx);
    } else {
      dist += clockwise_dist(n, next_idx, pos);
    }

    int remain_next = track[next_idx] - 1;
    int remain_far = track[far_idx];

    int t = 0;
    if (remain_next > 0 && remain_far > 0) {
      t = min(remain_next, remain_far);
    }

    int seg_dist;  // 두 지점 사이 거리
    if (dir == 0) {
      seg_dist = clockwise_dist(n, far_idx, next_idx);
    } else {
      seg_dist = clockwise_dist(n, next_idx, far_idx);
    }

    dist += 2LL * seg_dist * t;

    // 쓰레기 개수 갱신
    track[next_idx] -= (t + 1);
    track[far_idx] -= t;

    pos = next_idx;

    // 쓰레기가 0개가 된 구역 제거
    if (!dque.empty() && track[left] == 0) dque.pop_front();
    if (!dque.empty() && track[right] == 0) dque.pop_back();

    // 만약 next_idx에 쓰레기가 남아 있으면
    if (track[next_idx] > 0) {
      dist += seg_dist;
      pos = far_idx;
    }

    dir = 1 - dir;
  }

  cout << dist;

  return 0;
}