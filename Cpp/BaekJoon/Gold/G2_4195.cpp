#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> friends;
unordered_map<string, int> friends_num;

string find(string f) {
  if (friends[f] == f) return f;

  return friends[f] = find(friends[f]);
}

void merge(string f1, string f2) {
  string temp1 = find(f1);
  string temp2 = find(f2);

  if (temp1 == temp2) return;

  friends[temp2] = temp1;
  friends_num[temp1] += friends_num[temp2];
}

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    friends.clear();
    friends_num.clear();

    int F;
    cin >> F;

    for (int f = 0; f < F; f++) {
      string f1, f2;
      cin >> f1 >> f2;

      if (friends.count(f1) == 0) {
        friends.insert({f1, f1});
        friends_num.insert({f1, 1});
      }

      if (friends.count(f2) == 0) {
        friends.insert({f2, f2});
        friends_num.insert({f2, 1});
      }

      merge(f1, f2);

      cout << friends_num[friends[f1]] << "\n";
    }
  }

  return 0;
}