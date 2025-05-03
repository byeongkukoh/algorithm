#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  deque<int> dque;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    if (temp == "push_front") {
      int num;
      cin >> num;

      dque.push_front(num);
    } else if (temp == "push_back") {
      int num;
      cin >> num;

      dque.push_back(num);
    } else if (temp == "pop_front") {
      if (dque.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dque.front() << "\n";
        dque.pop_front();
      }
    } else if (temp == "pop_back") {
      if (dque.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dque.back() << "\n";
        dque.pop_back();
      }
    } else if (temp == "size") {
      cout << dque.size() << "\n";
    } else if (temp == "empty") {
      if (dque.empty()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else if (temp == "front") {
      if (dque.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dque.front() << "\n";
      }
    } else if (temp == "back") {
      if (dque.empty()) {
        cout << -1 << "\n";
      } else {
        cout << dque.back() << "\n";
      }
    }
  }

  return 0;
}