// 二叉树的最大深度

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
    int maxDepth(TreeNode* root) {
      if (!root) {
        return 0;
      }
      if (root->left == nullptr && root->right == nullptr) {
          return 1;
      }
      int rightDepth = 0, leftDepth = 0;
      if (root->right) {
        rightDepth = maxDepth(root->right);
      }
      if (root->left) {
        leftDepth = maxDepth(root->left);
      }
      return std::max(rightDepth, leftDepth) + 1;
    }
};