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
    TreeNode* dfs(vector<int>& nums, int left, int right) {
      if (left > right) {
        return nullptr;
      }
      int mid = (left + right) / 2;
      auto* val = new TreeNode(nums[mid]);
      val->left = dfs(nums, left, mid - 1);
      val->right = dfs(nums, mid + 1, right);
      return val;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return dfs(nums, 0, nums.size() - 1);
    }
};