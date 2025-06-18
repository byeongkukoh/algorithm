#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
unordered_map<int, int> countNum;

void InsertNum(int x) {
  maxHeap.push(x);
  minHeap.push(x);

  countNum[x]++;
}

void eraseMax() {
  while (!maxHeap.empty()) {
    int x = maxHeap.top();
    maxHeap.pop();

    if (countNum[x] > 0) {
      countNum[x]--;
      break;
    }
  }
}

void eraseMin() {
  while (!minHeap.empty()) {
    int x = minHeap.top();
    minHeap.pop();

    if (countNum[x] > 0) {
      countNum[x]--;
      break;
    }
  }
}

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    while (!maxHeap.empty()) maxHeap.pop();
    while (!minHeap.empty()) minHeap.pop();
    countNum.clear();

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
      char comm;
      cin >> comm;

      if (comm == 'I') {
        int num;
        cin >> num;

        InsertNum(num);
        continue;
      }

      if (comm == 'D') {
        int mm;
        cin >> mm;

        if (mm == -1) {
          eraseMin();
        } else {
          eraseMax();
        }
      }
    }

    int maxVal = 0, minVal = 0;
    bool foundMax = false, foundMin = false;

    while (!maxHeap.empty()) {
      int x = maxHeap.top();
      if (countNum[x] > 0) {
        maxVal = x;
        foundMax = true;
        break;
      }
      maxHeap.pop();
    }

    while (!minHeap.empty()) {
      int x = minHeap.top();
      if (countNum[x] > 0) {
        minVal = x;
        foundMin = true;
        break;
      }
      minHeap.pop();
    }

    if (!foundMax || !foundMin) {
      cout << "EMPTY\n";
    } else {
      cout << maxVal << " " << minVal << "\n";
    }
  }

  return 0;
}