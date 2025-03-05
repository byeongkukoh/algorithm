#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<string, string> passwordList;

  for (int i = 0; i < n; i++) {
    string site, pw;
    cin >> site >> pw;

    passwordList[site] = pw;
  }

  for (int i = 0; i < m; i++) {
    string check;
    cin >> check;

    cout << passwordList[check] << "\n";
  }

  return 0;
}