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
  int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);

    int nowLevel = 1;
    int resultLevel = -1;

    long long maxSum = INT_MIN;

    while (!que.empty()) {
      int loopSize = que.size();
      long long currSum = 0;

      for (int i = 0; i < loopSize; i++) {
        TreeNode* now = que.front();
        que.pop();

        currSum += now->val;

        if (now->left) que.push(now->left);
        if (now->right) que.push(now->right);
      }

      if (currSum > maxSum) {
        maxSum = currSum;
        resultLevel = nowLevel;
      }

      nowLevel++;
    }

    return resultLevel;
  }
};