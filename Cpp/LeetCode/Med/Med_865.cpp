// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode* left, TreeNode* right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 public:
  TreeNode* lca(TreeNode* a, TreeNode* b, const vector<TreeNode*>& parent) {
    vector<int> ansc;

    while (a) {
      ansc.push_back(a->val);

      a = parent[a->val];
    }

    while (b) {
      auto target = find(ansc.begin(), ansc.end(), b->val);

      if (target == ansc.end()) {
        b = parent[b->val];
        continue;
      }

      return b;
    }

    return nullptr;
  }

  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    vector<TreeNode*> parent(501, nullptr);
    vector<TreeNode*> nodeMap(501, nullptr);

    vector<vector<int>> deep(500);

    queue<TreeNode*> que;
    que.push(root);

    int level = 0;
    TreeNode* last;

    while (!que.empty()) {
      int size = que.size();

      for (int i = 0; i < size; i++) {
        TreeNode* now = que.front();
        que.pop();

        nodeMap[now->val] = now;

        if (now->left) {
          que.push(now->left);
          parent[now->left->val] = now;
        }
        if (now->right) {
          que.push(now->right);
          parent[now->right->val] = now;
        }

        last = now;
        deep[level].push_back(now->val);
      }

      level++;
    }

    vector<int> deepest = deep[level - 1];
    TreeNode* result = nodeMap[deepest[0]];

    for (int i = 1; i < deepest.size(); i++) {
      result = lca(result, nodeMap[deepest[i]], parent);
    }

    return result;
  }
};