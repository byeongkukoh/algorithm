#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
};

vector<string> MAP;
vector<vector<bool>> visited;

int height, width;
bool keys[26] = {false};
int result = 0;

vector<vector<Node>> doors;

// 방향 배열
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// 초기화 함수
void init() {
  result = 0;

  MAP.clear();
  visited.clear();

  doors.clear();
  doors.resize(26);

  for (int i = 0; i < 26; i++) keys[i] = false;
}

// BFS 수행
void bfs() {
  queue<Node> que;
  que.push({0, 0});

  visited[0][0] = true;

  while (!que.empty()) {
    Node now = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= height + 2 || nx >= width + 2) continue;
      if (MAP[ny][nx] == '*') continue;
      if (visited[ny][nx]) continue;

      // 문에 도달한 경우
      if (MAP[ny][nx] >= 'A' && MAP[ny][nx] <= 'Z') {
        // 키를 가지고 있으면, 그냥 진행
        if (keys[MAP[ny][nx] - 'A']) {
          que.push({ny, nx});
          visited[ny][nx] = true;
          continue;
        }
        // 키가 없으면 방문 처리만 하고 continue
        // -> 키 찾으면 que에 추가해서 bfs 이어서 진행 예정
        else {
          visited[ny][nx] = true;
          continue;
        }
      }

      // 키에 도달한 경우
      if (MAP[ny][nx] >= 'a' && MAP[ny][nx] <= 'z') {
        // 가지고 있는 키 목록 추가
        keys[MAP[ny][nx] - 'a'] = true;
        visited[ny][nx] = true;
        que.push({ny, nx});

        // 방문했던 문이 있으면 큐에 추가
        for (int j = 0; j < doors[MAP[ny][nx] - 'a'].size(); j++) {
          Node door = doors[MAP[ny][nx] - 'a'][j];

          if (visited[door.y][door.x]) que.push({door.y, door.x});
        }

        continue;
      }

      // 그냥 길인 경우
      que.push({ny, nx});
      visited[ny][nx] = true;

      // 문서인 경우 count++
      if (MAP[ny][nx] == '$') result++;
    }
  }
}

// 메인함수
int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    // 초기화 함수 실행
    init();

    // 테스트케이스 시작
    cin >> height >> width;

    visited.assign(height + 2, vector<bool>(width + 2, false));

    // 지도 입력
    string temp = "";
    for (int i = 0; i < width + 2; i++) {
      temp += '.';
    }

    MAP.push_back(temp);
    for (int i = 0; i < height; i++) {
      string line;
      cin >> line;

      line = '.' + line + '.';
      MAP.push_back(line);

      for (int j = 0; j < width + 2; j++) {
        if (MAP[i + 1][j] >= 'A' && MAP[i + 1][j] <= 'Z') {
          doors[MAP[i + 1][j] - 'A'].push_back({i + 1, j});
        }
      }
    }
    MAP.push_back(temp);

    // 초기 열쇠 목록 입력
    string keyList;
    cin >> keyList;

    if (keyList != "0") {
      for (int i = 0; i < keyList.length(); i++) {
        keys[keyList[i] - 'a'] = true;
      }
    }

    // 탐색 시작
    bfs();

    cout << result << "\n";
  }

  return 0;
}