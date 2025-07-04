#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    string comm;
    cin >> comm;

    int n;
    cin >> n;

    deque<int> deq;

    string numbers;
    cin >> numbers;

    string temp = "";

    for (int i = 0; i < numbers.size(); i++) {
      if (numbers[i] >= '0' && numbers[i] <= '9') {
        temp += numbers[i];
        continue;
      }

      if (temp == "") continue;

      deq.push_back(stoi(temp));

      temp = "";
    }

    int dir = 0;  // 0: front, 1: back
    bool check_error = false;
    for (int i = 0; i < comm.size(); i++) {
      if (comm[i] == 'R') {
        dir = (dir + 1) % 2;
      } else {
        if (deq.empty()) {
          check_error = true;
          break;
        }
        if (dir == 0) {
          deq.pop_front();
        } else {
          deq.pop_back();
        }
      }
    }

    if (check_error) {
      cout << "error" << "\n";
    } else {
      cout << "[";
      if (!deq.empty()) {
        while (true) {
          if (dir == 0) {
            cout << deq.front();
            deq.pop_front();
          } else {
            cout << deq.back();
            deq.pop_back();
          }

          if (deq.empty()) break;

          cout << ",";
        }
      }
      cout << "]\n";
    }
  }

  return 0;
}