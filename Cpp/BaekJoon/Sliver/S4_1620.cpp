#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, string> pokemon_idx;
  map<string, int> pokemon_name;
  // vector<string> pokemon;

  for (int i = 0; i < n; i++) {
    string temp_name;
    cin >> temp_name;

    pokemon_idx.insert({i, temp_name});
    pokemon_name.insert({temp_name, i});
  }

  for (int i = 0; i < m; i++) {
    string pro;
    cin >> pro;

    if (pro[0] >= '0' && pro[0] <= '9') {
      cout << pokemon_idx[stoi(pro) - 1] << "\n";
    } else {
      cout << pokemon_name[pro] + 1 << "\n";
    }
  }

  return 0;
}