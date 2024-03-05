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
    int maxSum = INT_MIN;

public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftVal = dfs(root->left);
        int rightVal = dfs(root->right);
        int curVal = leftVal + rightVal + root->val;
        maxSum = std::max(maxSum, curVal);
        // 对上提供路径和只能左右子树选其一，如果都是负数，选0，即返回自己
        int resVal = root->val + std::max(0, std::max(leftVal, rightVal));
        return resVal < 0 ? 0 : resVal;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};