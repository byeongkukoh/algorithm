#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < n; i++) {
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

    cout << maxHeap.top() << "\n";
  }

  return 0;
}