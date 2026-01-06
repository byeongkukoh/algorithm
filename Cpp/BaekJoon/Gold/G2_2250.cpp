#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int node;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int n) : node(n), left(nullptr), right(nullptr) {}
};

// 중위 순회
void dfs(TreeNode* node, int level, vector<int>& minCol, vector<int>& maxCol,
         int& maxLevel, int& column) {
  if (!node) return;

  maxLevel = max(level, maxLevel);

  dfs(node->left, level + 1, minCol, maxCol, maxLevel, column);

  minCol[level] = min(minCol[level], column);
  maxCol[level] = max(maxCol[level], column);
  column++;

  dfs(node->right, level + 1, minCol, maxCol, maxLevel, column);
}

int main() {
  int N;
  cin >> N;

  // 트리 생성
  vector<TreeNode*> tree(N + 1);
  vector<bool> hasParent(N + 1, false);
  for (int i = 0; i < N + 1; i++) {
    tree[i] = new TreeNode(i);
  }

  for (int i = 0; i < N; i++) {
    int node, left, right;
    cin >> node >> left >> right;

    if (left != -1) {
      tree[node]->left = tree[left];
      hasParent[left] = true;
    }

    if (right != -1) {
      tree[node]->right = tree[right];
      hasParent[right] = true;
    }
  }

  // 부모 노드 찾기
  TreeNode* root = nullptr;
  for (int i = 1; i < N + 1; i++) {
    if (!hasParent[i]) {
      root = tree[i];
    }
  }

  // 중위 순회
  int maxLevel = 0, column = 1;
  vector<int> minCol(N + 1, INT_MAX);
  vector<int> maxCol(N + 1, 0);

  dfs(root, 1, minCol, maxCol, maxLevel, column);

  // 정답 찾기
  int resLevel = 1, resWidth = 1;
  for (int i = 1; i <= maxLevel; i++) {
    int temp = maxCol[i] - minCol[i] + 1;

    if (temp > resWidth) {
      resWidth = temp;
      resLevel = i;
    }
  }

  cout << resLevel << " " << resWidth << "\n";

  return 0;
}