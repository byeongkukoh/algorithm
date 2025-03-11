#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int display;    // 현재 화면에 있는 이모티콘 개수
  int capture;    // 복사된 이모티콘의 개수
  int need_time;  // 소요된 시간
};

int main() {
  int s;
  cin >> s;

  vector<vector<int>> visited;  // s개 표출하고, C개 복사했을 때 체크 여부
  visited.resize(2001, vector<int>(2001, 0));

  Node start_state = {1, 0, 0};  // 화면, 복사, 시간

  queue<Node> que;
  que.push(start_state);

  visited[1][0] = 1;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    if (now.display == s) {
      cout << now.need_time;
      return 0;
    }

    // 1. 복사
    if (!visited[now.display][now.display]) {
      que.push({now.display, now.display, now.need_time + 1});
      visited[now.display][now.display] = 1;
    }

    // 2. 붙여넣기
    if (now.capture > 0 && !visited[now.display + now.capture][now.capture] &&
        now.display + now.capture <= 1000) {
      que.push({now.display + now.capture, now.capture, now.need_time + 1});
      visited[now.display + now.capture][now.capture] = 1;
    }

    // 3. 하나 제거
    if (now.display >= 1 && !visited[now.display - 1][now.capture]) {
      que.push({now.display - 1, now.capture, now.need_time + 1});
      visited[now.display - 1][now.capture] = 1;
    }
  }

  return 0;
}