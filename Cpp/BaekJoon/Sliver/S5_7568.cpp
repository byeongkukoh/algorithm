#include <iostream>
#include <vector>

using namespace std;

struct Person {
  int weight;
  int height;
  int score;
};

int main() {
  int N;
  cin >> N;

  vector<Person> person;

  for (int idx = 0; idx < N; idx++) {
    int weight, height;
    cin >> weight >> height;
    person.push_back({weight, height, 0});
  }

  for (int i = 0; i < N; i++) {
    int count = 1;
    for (int j = 0; j < N; j++) {
      if (person[i].weight < person[j].weight &&
          person[i].height < person[j].height) {
        count++;
      }
    }
    person[i].score = count;
  }

  for (int i = 0; i < N; i++) {
    cout << person[i].score << " ";
  }

  return 0;
}