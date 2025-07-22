#include <iostream>
#include <queue>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int m;
    cin >> m;

    cout << m / 2 + 1 << "\n";

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < m; i++) {
      int temp;
      cin >> temp;

      if (maxHeap.empty() || maxHeap.top() >= temp) {
        maxHeap.push(temp);
      } else {
        minHeap.push(temp);
      }

      if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      } else if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }

      if (i % 2 == 0) cout << maxHeap.top() << " ";
    }

    cout << "\n";
  }
  return 0;
}