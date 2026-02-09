/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> sortedNodes;

  void inorder(TreeNode* node) {
    if (node == nullptr) return;

    inorder(node->left);
    sortedNodes.push_back(node->val);
    inorder(node->right);
  }

  TreeNode* buildBalanceTree(int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(sortedNodes[mid]);

    node->left = buildBalanceTree(start, mid - 1);
    node->right = buildBalanceTree(mid + 1, end);

    return node;
  }

  TreeNode* balanceBST(TreeNode* root) {
    inorder(root);

    return buildBalanceTree(0, sortedNodes.size() - 1);
  }
};