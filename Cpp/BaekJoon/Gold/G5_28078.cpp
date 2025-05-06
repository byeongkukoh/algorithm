#include <deque>
#include <iostream>
#include <string>

using namespace std;

int cur_state = 0;
int count_ball = 0;
int count_wall = 0;

deque<char> dque;

void push_ball() {
  dque.push_front('b');
  count_ball++;
}

void push_wall() {
  dque.push_front('w');
  count_wall++;
}

void pop_que() {
  if (*(--dque.end()) == 'b')
    count_ball--;
  else if (*(--dque.end()) == 'w')
    count_wall--;

  dque.pop_back();
}

void rotate_que(char dir) {
  if (dir == 'l') {
    cur_state = (cur_state - 90 + 360) % 360;
  } else if (dir == 'r') {
    cur_state = (cur_state + 90) % 360;
  }

  return;
}

void count_que(char some) {
  if (some == 'b')
    cout << count_ball << "\n";
  else if (some == 'w')
    cout << count_wall << "\n";
}

void check_state() {
  if (cur_state == 0 || cur_state == 180) return;

  if (cur_state == 90) {
    while (true) {
      if (dque.empty()) return;
      if (dque[dque.size() - 1] == 'w') return;

      dque.pop_back();
      count_ball--;
    }
  }

  if (cur_state == 270) {
    while (true) {
      if (dque.empty()) return;
      if (dque[0] == 'w') return;

      dque.pop_front();
      count_ball--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    string comm;
    cin >> comm;

    if (comm == "push") {
      char temp;
      cin >> temp;

      if (temp == 'b') {
        push_ball();
      } else {
        push_wall();
      }
    } else if (comm == "pop") {
      if (dque.empty()) continue;

      pop_que();
    } else if (comm == "rotate") {
      char temp;
      cin >> temp;

      rotate_que(temp);
    } else if (comm == "count") {
      char temp;
      cin >> temp;

      count_que(temp);
    }

    check_state();
  }

  return 0;
}