// 翻转二叉树

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (!root) {
        return nullptr;
      }
      auto* leftNode = invertTree(root->left);
      auto* rightNode = invertTree(root->right);
      root->right = leftNode;
      root->left = rightNode;
      return root;
    }
};