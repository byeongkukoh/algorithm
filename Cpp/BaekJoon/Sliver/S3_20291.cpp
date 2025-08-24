#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, int> files;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string file;
    cin >> file;

    int dotIdx = file.find('.');

    files[file.substr(dotIdx + 1)] += 1;
  }

  for (auto file : files) {
    cout << file.first << " " << file.second << endl;
  }

  return 0;
}