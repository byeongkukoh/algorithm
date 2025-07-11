#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) return 0;

    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;  // index 저장
    long long area = 0;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        long long height = arr[st.top()];
        st.pop();

        int width;
        if (st.empty()) {
          width = i;
        } else {
          width = i - st.top() - 1;
        }

        area = max(area, height * width);
      }

      st.push(i);
    }

    while (!st.empty()) {
      long long height = arr[st.top()];
      st.pop();

      int width;
      if (st.empty()) {
        width = n;
      } else {
        width = n - st.top() - 1;
      }

      area = max(area, height * width);
    }

    cout << area << "\n";
  }
}