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
    unordered_map<long long, int> preSum;
    int res = 0;
    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (!root) {
            return;
        }
        sum += root->val;
        // 减去targetSum后的sum的路径数目
        res += preSum.contains(sum - targetSum) ? preSum[sum - targetSum] : 0;
        // 当前sum的路径数目
        preSum[sum]++;
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
        // 消除当前分支的影响，因为是深度优先遍历
        preSum[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        // 前缀和+哈希map
        preSum.insert({0, 1});
        dfs(root, 0, targetSum);
        return res;
    }
};