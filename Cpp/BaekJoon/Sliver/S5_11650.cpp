#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Coord {
  int x;
  int y;
};

bool cmp(Coord left, Coord right) {
  if (left.x < right.x) return true;
  if (left.x > right.x) return false;

  if (left.y < right.y) return true;
  if (left.y > right.y) return false;

  return false;
}

int main() {
  int N;
  cin >> N;

  vector<Coord> coords;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    coords.push_back({x, y});
  }

  sort(coords.begin(), coords.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << coords[i].x << " " << coords[i].y << "\n";
  }

  return 0;
}