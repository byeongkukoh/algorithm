#include <stdio.h>

struct Node {
  char value;
  int left;
  int right;
};

struct Node tree[26];

void preorder(int node) {
  if (node == -1) return;

  printf("%c", tree[node].value);
  preorder(tree[node].left);
  preorder(tree[node].right);
}

void inorder(int node) {
  if (node == -1) return;

  inorder(tree[node].left);
  printf("%c", tree[node].value);
  inorder(tree[node].right);
}

void postorder(int node) {
  if (node == -1) return;

  postorder(tree[node].left);
  postorder(tree[node].right);
  printf("%c", tree[node].value);
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < 26; i++) {
    tree[i].left = -1;
    tree[i].right = -1;
  }

  for (int i = 0; i < n; i++) {
    char p, l, r;
    scanf(" %c %c %c", &p, &l, &r);

    tree[p - 'A'].value = p;
    tree[p - 'A'].left = (l == '.' ? -1 : l - 'A');
    tree[p - 'A'].right = (r == '.' ? -1 : r - 'A');
  }

  preorder(0);
  printf("\n");

  inorder(0);
  printf("\n");

  postorder(0);
  printf("\n");

  return 0;
}