#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string n;
int numlen;
vector<char> path;
vector<char> posNums;

int mindiff = INT_MAX;
int mindiff2 = INT_MAX;
int mindiff3 = INT_MAX;

void func(int now) {
  if (now == numlen) {
    string new_number = "";

    for (int i = 0; i < numlen; i++) {
      new_number += path[i];
    }

    int diff = abs(stoi(new_number) - stoi(n));

    if (diff < mindiff) {
      mindiff = diff;
    }

    // cout << new_number << "\n";

    return;
  }

  for (int i = 0; i < posNums.size(); i++) {
    path.push_back(posNums[i]);

    func(now + 1);

    path.pop_back();
  }
}

void func2(int now) {
  if (now == numlen - 1) {
    string new_number = "";

    for (int i = 0; i < numlen - 1; i++) {
      new_number += path[i];
    }

    int diff = abs(stoi(new_number) - stoi(n));

    if (diff < mindiff2) {
      mindiff2 = diff;
    }

    // cout << new_number << "\n";

    return;
  }

  for (int i = 0; i < posNums.size(); i++) {
    path.push_back(posNums[i]);

    func2(now + 1);

    path.pop_back();
  }
}

void func3(int now) {
  if (now == numlen + 1) {
    string new_number = "";

    for (int i = 0; i < numlen + 1; i++) {
      new_number += path[i];
    }

    int diff = abs(stoi(new_number) - stoi(n));

    if (diff < mindiff3) {
      mindiff3 = diff;
    }

    // cout << new_number << "\n";

    return;
  }

  for (int i = 0; i < posNums.size(); i++) {
    path.push_back(posNums[i]);

    func3(now + 1);

    path.pop_back();
  }
}

int main() {
  cin >> n;

  numlen = n.length();

  // cout << numlen << "\n";

  int m;
  cin >> m;

  for (char i = '0'; i <= '9'; i++) {
    posNums.push_back(i);
  }

  for (int i = 0; i < m; i++) {
    char temp;
    cin >> temp;

    posNums.erase(remove(posNums.begin(), posNums.end(), temp), posNums.end());
  }

  func(0);

  if (numlen - 1 != 0) {
    func2(0);
  }

  func3(0);

  int ans = abs(stoi(n) - 100);

  if (mindiff != INT_MAX) {
    ans = min(ans, mindiff + numlen);
  }

  if (mindiff2 != INT_MAX) {
    ans = min(ans, mindiff2 + numlen - 1);
  }

  if (mindiff3 != INT_MAX) {
    ans = min(ans, mindiff3 + numlen + 1);
  }

  cout << ans;

  return 0;
}