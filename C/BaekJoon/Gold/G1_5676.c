#include <stdio.h>

#define MAX_N 100000

int n, k;
int arr[MAX_N + 2];
int tree[4 * MAX_N + 50];

int sign(int val) {
  if (val < 0) return -1;
  if (val > 0) return 1;
  return 0;
}

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];

    return;
  }

  int mid = (start + end) / 2;

  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);

  tree[node] = tree[2 * node] * tree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    arr[idx] = sign(val);
    tree[node] = arr[idx];

    return;
  }

  int mid = (start + end) / 2;

  if (idx <= mid)
    update(2 * node, start, mid, idx, val);
  else
    update(2 * node + 1, mid + 1, end, idx, val);

  tree[node] = tree[2 * node] * tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return 1;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  int ql = query(2 * node, start, mid, left, right);
  int qr = query(2 * node + 1, mid + 1, end, left, right);

  return ql * qr;
}

void init(int n) {
  for (int i = 1; i <= n; i++) arr[i] = 1;
  for (int i = 1; i <= 4 * n; i++) tree[i] = 1;
}

int main() {
  while (scanf("%d %d", &n, &k) == 2) {
    init(n);

    for (int i = 1; i <= n; i++) {
      int temp;
      scanf("%d", &temp);

      arr[i] = sign(temp);
    }

    build(1, 1, n);

    for (int i = 0; i < k; i++) {
      char comm;
      scanf(" %c", &comm);

      if (comm == 'C') {
        int idx, val;
        scanf("%d %d", &idx, &val);

        update(1, 1, n, idx, val);
      } else {
        int left, right;
        scanf("%d %d", &left, &right);

        int res = query(1, 1, n, left, right);

        if (res < 0)
          printf("-");
        else if (res == 0)
          printf("0");
        else
          printf("+");
      }
    }

    printf("\n");
  }
  return 0;
}
