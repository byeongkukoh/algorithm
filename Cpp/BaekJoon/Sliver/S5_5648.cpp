#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> vect;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    reverse(temp.begin(), temp.end());

    vect.push_back(stol(temp));
  }

  sort(vect.begin(), vect.end());

  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << "\n";
  }

  return 0;
}