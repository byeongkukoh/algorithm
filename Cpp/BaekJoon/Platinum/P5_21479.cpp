#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string left, string right) {
  if (left + right > right + left) return true;
  if (left + right < right + left) return false;

  return false;
}

int main() {
  vector<string> numList;

  while (1) {
    string temp;
    cin >> temp;

    if (cin.eof()) break;

    numList.push_back(temp);
  }

  sort(numList.begin(), numList.end(), cmp);

  for (int i = 0; i < numList.size(); i++) {
    cout << numList[i];
  }

  return 0;
}