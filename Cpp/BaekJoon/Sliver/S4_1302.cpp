#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, int> books;

  for (int i = 0; i < n; i++) {
    string title;
    cin >> title;

    books[title] += 1;
  }

  string title;
  int max_cnt = 0;

  for (auto it = books.begin(); it != books.end(); it++) {
    int val = it->second;

    if (val > max_cnt) {
      max_cnt = val;
      title = it->first;
    }
  }

  cout << title << "\n";

  return 0;
}