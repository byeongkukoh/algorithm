#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int i = 0; i < test; i++) {
    map<string, vector<string>> clothes;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      string cloth, type;
      cin >> cloth >> type;

      clothes[type].push_back(cloth);
    }

    int result = 1;
    for (auto& cloth : clothes) {
      result *= (cloth.second.size() + 1);
    }

    cout << result - 1 << "\n";
  }

  return 0;
}