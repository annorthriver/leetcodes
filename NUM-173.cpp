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
class BSTIterator {
public:
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        nodes.emplace_back(root->val);
        dfs(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {     
        dfs(root);
    }

    int next() {
        return nodes[idx++];
    }

    bool hasNext() { return idx < nodes.size(); }
    std::vector<int> nodes;
    int idx = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */