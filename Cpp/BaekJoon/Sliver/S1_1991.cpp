#include <iostream>

using namespace std;

struct Node {
  char node;
  Node* left;
  Node* right;

  Node(char v) : node(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* node) {
  if (!node) return;

  cout << node->node;
  preorder(node->left);
  preorder(node->right);
}

void inorder(Node* node) {
  if (!node) return;

  inorder(node->left);
  cout << node->node;
  inorder(node->right);
}

void postorder(Node* node) {
  if (!node) return;

  postorder(node->left);
  postorder(node->right);
  cout << node->node;
}

int main() {
  Node* tree[26] = {nullptr};

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char p, l, r;
    cin >> p >> l >> r;

    if (!tree[p - 'A']) tree[p - 'A'] = new Node(p);
    if (l != '.' && !tree[l - 'A']) tree[l - 'A'] = new Node(l);
    if (r != '.' && !tree[r - 'A']) tree[r - 'A'] = new Node(r);

    tree[p - 'A']->left = (l == '.' ? nullptr : tree[l - 'A']);
    tree[p - 'A']->right = (r == '.' ? nullptr : tree[r - 'A']);
  }

  Node* root = tree['A' - 'A'];

  preorder(root);
  cout << "\n";

  inorder(root);
  cout << "\n";

  postorder(root);
  cout << "\n";

  return 0;
}