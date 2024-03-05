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
    int dfs(TreeNode* root, int preSum) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return preSum + root->val;
        }
        int curVal = (preSum + root->val) * 10;
        return dfs(root->left, curVal) + dfs(root->right, curVal);
    }
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }
};