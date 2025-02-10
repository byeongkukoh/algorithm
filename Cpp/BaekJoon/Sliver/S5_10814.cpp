#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Member {
  int index;
  int age;
  string name;
};

bool cmp(Member left, Member right) {
  if (left.age < right.age) return true;
  if (left.age > right.age) return false;

  if (left.index < right.index) return true;
  if (left.index > right.index) return false;

  return false;
}

int main() {
  int N;
  cin >> N;

  vector<Member> members;

  for (int i = 0; i < N; i++) {
    int age;
    string name;
    cin >> age >> name;

    members.push_back({i + 1, age, name});
  }

  sort(members.begin(), members.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << members[i].age << " " << members[i].name << "\n";
  }

  return 0;
}