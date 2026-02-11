#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> party_people;
vector<vector<int>> parties;

int find(int a) {
  if (parent[a] == a) return parent[a];

  return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
  int pa = find(a);
  int pb = find(b);

  if (pa == pb) return;
  if (pa > pb) swap(pa, pb);

  parent[pb] = parent[pa];
}

int main() {
  int N, M;
  cin >> N >> M;

  parent.assign(N + 1, 0);
  for (int i = 0; i < N + 1; i++) {
    parent[i] = i;
  }

  party_people.assign(M, 0);
  parties.assign(M, vector<int>());

  int truth_cnt;
  cin >> truth_cnt;

  for (int i = 0; i < truth_cnt; i++) {
    int temp;
    cin >> temp;

    parent[temp] = 0;
  }

  for (int i = 0; i < M; i++) {
    int people;
    cin >> people;
    party_people[i] = people;

    int temp;
    cin >> temp;
    parties[i].push_back(temp);

    for (int j = 1; j < people; j++) {
      int temp2;
      cin >> temp2;

      parties[i].push_back(temp2);
      merge(temp, temp2);
    }
  }

  int answer = M;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < party_people[i]; j++) {
      if (find(parties[i][j]) == 0) {
        answer--;
        break;
      }
    }
  }

  cout << answer;

  return 0;
}