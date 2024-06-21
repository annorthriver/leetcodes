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
    // 方法一：递归版本，中序dfs
    // 左闭右闭区间[left, right]，left和right都要能取到
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
    // 方法二：迭代版本，bfs
    // 通过三个队列来模拟，一个队列放遍历的节点，一个队列放左区间下标，一个队列放右区间下标。
};