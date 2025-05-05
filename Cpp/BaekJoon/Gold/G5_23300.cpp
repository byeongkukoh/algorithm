#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> backward_page;
deque<int> frontward_page;

int curr_page;

void backward(int page) {
  if (backward_page.empty()) return;

  frontward_page.push_front(page);
  curr_page = backward_page.back();
  backward_page.pop_back();
}

void frontward(int page) {
  if (frontward_page.empty()) return;

  backward_page.push_back(page);
  curr_page = frontward_page.front();
  frontward_page.pop_front();
}

void access(int page) {
  frontward_page.clear();

  if (curr_page != 0) {
    backward_page.push_back(curr_page);
  }

  curr_page = page;
}

void comp() {
  vector<int> temp;

  for (int i = 0; i < backward_page.size(); i++) {
    int now = backward_page[i];

    if (temp.empty()) {
      temp.push_back(backward_page[i]);
    } else if (temp.back() == now) {
      continue;
    } else {
      temp.push_back(now);
    }
  }

  backward_page.clear();
  backward_page = temp;
}

int main() {
  int N, Q;
  cin >> N >> Q;

  curr_page = 0;  // 접속하지 않은 상태

  for (int i = 0; i < Q; i++) {
    char comm;
    cin >> comm;

    if (comm == 'B') {
      backward(curr_page);
    } else if (comm == 'F') {
      frontward(curr_page);
    } else if (comm == 'A') {
      int pg;
      cin >> pg;

      access(pg);
    } else if (comm == 'C') {
      comp();
    }
  }

  cout << curr_page << "\n";

  if (backward_page.empty()) {
    cout << -1 << "\n";
  } else {
    for (int i = backward_page.size() - 1; i >= 0; i--) {
      cout << backward_page[i] << " ";
    }
    cout << "\n";
  }

  if (frontward_page.empty()) {
    cout << -1;
  } else {
    for (int i = 0; i < frontward_page.size(); i++) {
      cout << frontward_page[i] << " ";
    }
  }

  return 0;
}