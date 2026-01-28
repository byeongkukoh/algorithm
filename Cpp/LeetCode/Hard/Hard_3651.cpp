class Solution {
 public:
  struct PQItem {
    int row, col, tel, cost;

    bool operator<(const PQItem& other) const {
      if (cost != other.cost) return cost > other.cost;

      return false;
    }
  };

  struct Cell {
    int cost, row, col;

    bool operator<(const Cell& other) const {
      if (cost != other.cost) return cost < other.cost;

      return false;
    }
  };

  int dy[2] = {1, 0};
  int dx[2] = {0, 1};

  int minCost(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    // 모든 셀 값을 기준으로 정렬 진행
    vector<Cell> sorted_cells;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sorted_cells.push_back({grid[i][j], i, j});
      }
    }
    sort(sorted_cells.begin(), sorted_cells.end());

    vector<int> k_process_idx(k + 1, 0);
    vector<vector<vector<int>>> visited(
        k + 1, vector<vector<int>>(n, vector<int>(m, INT_MAX)));

    priority_queue<PQItem> pque;
    pque.push({0, 0, 0, 0});

    visited[0][0][0] = 0;

    while (!pque.empty()) {
      PQItem now = pque.top();
      pque.pop();

      if (visited[now.tel][now.row][now.col] < now.cost) continue;

      // 목적지 도착하면 종료
      if (now.row == n - 1 && now.col == m - 1) return now.cost;

      // 일반적인 이동 탐색
      for (int i = 0; i < 2; i++) {
        int ny = now.row + dy[i];
        int nx = now.col + dx[i];

        // 경계를 벗어나는 경우
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        int next_cost = now.cost + grid[ny][nx];
        if (visited[now.tel][ny][nx] <= next_cost) continue;

        pque.push({ny, nx, now.tel, next_cost});
        visited[now.tel][ny][nx] = next_cost;
      }

      // 텔레포트 탐색
      if (now.tel < k) {
        int curr_value = grid[now.row][now.col];
        int next_tel = now.tel + 1;

        while (k_process_idx[now.tel] < sorted_cells.size()) {
          Cell target = sorted_cells[k_process_idx[now.tel]];

          if (target.cost > curr_value) break;

          k_process_idx[now.tel]++;

          if ((target.row == now.row && target.col == now.col) ||
              (visited[next_tel][target.row][target.col] <= now.cost))
            continue;

          visited[next_tel][target.row][target.col] = now.cost;
          pque.push({target.row, target.col, next_tel, now.cost});
        }
      }
    }

    return 0;
  }
};