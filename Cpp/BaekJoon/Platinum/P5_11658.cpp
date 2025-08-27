#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<long long>> arr;
vector<vector<long long>> tree;

// 열 트리 빌드: 고정 row_node에서 빌드 진행
void build_col(int row_node, int row_left, int row_right, int col_node,
               int col_left, int col_right) {
  if (col_left == col_right) {
    if (row_left == row_right) {
      tree[row_node][col_node] = arr[row_left][col_left];
    } else {
      tree[row_node][col_node] =
          tree[row_node * 2][col_node] + tree[row_node * 2 + 1][col_node];
    }

    return;
  }

  int col_mid = (col_left + col_right) / 2;

  build_col(row_node, row_left, row_right, col_node * 2, col_left, col_mid);
  build_col(row_node, row_left, row_right, col_node * 2 + 1, col_mid + 1,
            col_right);

  tree[row_node][col_node] =
      tree[row_node][col_node * 2] + tree[row_node][col_node * 2 + 1];
}

// 행 트리 빌드: 각 row_node에 대해 열 트리 구성
void build_row(int row_node, int row_left, int row_right) {
  if (row_left != row_right) {
    int row_mid = (row_left + row_right) / 2;

    build_row(row_node * 2, row_left, row_mid);
    build_row(row_node * 2 + 1, row_mid + 1, row_right);
  }

  build_col(row_node, row_left, row_right, 1, 1, n);
}

// 열 트리 쿼리
long long query_col(int row_node, int col_node, int col_left, int col_right,
                    int col1, int col2) {
  if (col2 < col_left || col1 > col_right) return 0;  // 미겹침
  if (col1 <= col_left && col2 >= col_right)
    return tree[row_node][col_node];  // 완전 포함

  int col_mid = (col_left + col_right) / 2;

  return query_col(row_node, col_node * 2, col_left, col_mid, col1, col2) +
         query_col(row_node, col_node * 2 + 1, col_mid + 1, col_right, col1,
                   col2);
}

// 행 트리 쿼리
long long query_row(int row_node, int row_left, int row_right, int row1,
                    int row2, int col1, int col2) {
  if (row2 < row_left || row1 > row_right) return 0;  // 미겹침
  if (row1 <= row_left && row2 >= row_right)
    return query_col(row_node, 1, 1, n, col1,
                     col2);  // 완전 포함: row_node의 열 트리에서만 쿼리 수행

  int row_mid = (row_left + row_right) / 2;

  return query_row(row_node * 2, row_left, row_mid, row1, row2, col1, col2) +
         query_row(row_node * 2 + 1, row_mid + 1, row_right, row1, row2, col1,
                   col2);
}

// 열 트리 업데이트
void update_col(int row_node, int row_left, int row_right, int col_node,
                int col_left, int col_right, int col, long long val) {
  if (col_left == col_right) {
    if (row_left == row_right) {
      tree[row_node][col_node] = val;
    } else {
      tree[row_node][col_node] =
          tree[row_node * 2][col_node] + tree[row_node * 2 + 1][col_node];
    }

    return;
  }

  int col_mid = (col_left + col_right) / 2;

  if (col <= col_mid) {
    update_col(row_node, row_left, row_right, col_node * 2, col_left, col_mid,
               col, val);
  } else {
    update_col(row_node, row_left, row_right, col_node * 2 + 1, col_mid + 1,
               col_right, col, val);
  }

  tree[row_node][col_node] =
      tree[row_node][col_node * 2] + tree[row_node][col_node * 2 + 1];
}

// 행 트리 업데이트
void update_row(int row_node, int row_left, int row_right, int row, int col,
                long long val) {
  if (row_left == row_right) {
    update_col(row_node, row_left, row_right, 1, 1, n, col, val);
    return;
  }

  int row_mid = (row_left + row_right) / 2;

  if (row <= row_mid) {
    update_row(row_node * 2, row_left, row_mid, row, col, val);
  } else {
    update_row(row_node * 2 + 1, row_mid + 1, row_right, row, col, val);
  }

  update_col(row_node, row_left, row_right, 1, 1, n, col, val);
}

// 편의성 함수
long long sum_rect(int row1, int col1, int row2, int col2) {
  if (row1 > row2) swap(row1, row2);
  if (col1 > col2) swap(col1, col2);

  return query_row(1, 1, n, row1, row2, col1, col2);
}

void point_set(int row, int col, long long val) {
  update_row(1, 1, n, row, col, val);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  arr.assign(n + 1, vector<long long>(n + 1, 0));
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      cin >> arr[row][col];
    }
  }

  tree.assign(4 * n + 5, vector<long long>(4 * n + 5, 0));
  build_row(1, 1, n);

  for (int i = 0; i < m; i++) {
    int comm;
    cin >> comm;

    if (comm == 0) {
      int col, row;
      long long val;
      cin >> col >> row >> val;

      point_set(col, row, val);
    } else {
      int col1, row1, col2, row2;
      cin >> col1 >> row1 >> col2 >> row2;

      cout << sum_rect(col1, row1, col2, row2) << "\n";
    }
  }

  return 0;
}