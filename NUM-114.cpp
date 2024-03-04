/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 方法一：使用vector保存前序遍历的结果，然后建立链表关系，注意left置为0
    void dfs(TreeNode* root, std::vector<TreeNode*> &vec) {
      if (!root) return;
      vec.push_back(root);
      dfs(root->left, vec);
      dfs(root->right, vec);
      return;
    }
    void flatten(TreeNode* root) {
      // 使用vec保存前序遍历的结果，然后构建链表
      std::vector<TreeNode *> nodes;
      dfs(root, nodes);
      auto *curNode = root;
      for (int i = 1; i < nodes.size(); i++) {
        curNode->right = nodes[i];
        curNode->left = nullptr;
        curNode = nodes[i];
      }
      return;
    }
};

// 方法二：采用反前序遍历

// 方法三：前序遍历+展开同时，使用bfs