#include <iostream>
#include <vector>
using namespace std;

int main() {
  while (true) {
    char nums[6];
    cin >> nums;

    if (nums[0] == '0') {
      break;
    }

    int len;
    for (int i = 0; nums[i]; i++) {
      len = i + 1;
    }

    bool check = true;

    for (int i = 0; i < len / 2; i++) {
      if (nums[i] != nums[len - i - 1]) {
        check = false;
        break;
      }
    }

    if (check) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}