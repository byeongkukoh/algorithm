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
  long long totalSum = 0;
  long long result = 0;

  long long dfs(TreeNode* node) {
    if (!node) return 0;

    long long leftSum = dfs(node->left);
    long long rightSum = dfs(node->right);

    long long subtreeSum = leftSum + rightSum + node->val;

    result = max(result, (totalSum - subtreeSum) * subtreeSum);

    return subtreeSum;
  }

  int maxProduct(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      int loopSize = que.size();

      for (int i = 0; i < loopSize; i++) {
        TreeNode* now = que.front();
        que.pop();

        totalSum += now->val;

        if (now->left) que.push(now->left);
        if (now->right) que.push(now->right);
      }
    }

    dfs(root);

    return result % 1000000007;
  }
  D
};