#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string left, string right) { return left + right > right + left; }

int main() {
  int n;
  cin >> n;

  vector<string> vect;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    vect.push_back(temp);
  }

  sort(vect.begin(), vect.end(), cmp);

  string result = "";

  for (int i = 0; i < n; i++) {
    result += vect[i];
  }

  if (result[0] == '0')
    cout << 0;
  else
    cout << result;

  return 0;
}