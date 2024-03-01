
 #include <vector>
 #include <algorithm>
 using namespace std;
 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        auto* node = new TreeNode(preorder[0]);
        int pos = std::distance(
            inorder.begin(),
            std::find(inorder.begin(), inorder.end(), preorder[0]));
        auto leftInOrder = vector<int>(inorder.begin(), inorder.begin() + pos);
        auto rightInOrder =
            vector<int>(inorder.begin() + pos + 1, inorder.end());
        auto leftPreOrder = vector<int>(
            preorder.begin() + 1, preorder.begin() + 1 + leftInOrder.size());
        auto rightPreOrder = vector<int>(
            preorder.begin() + 1 + leftInOrder.size(), preorder.end());
        node->left = buildTree(leftPreOrder, leftInOrder);
        node->right = buildTree(rightPreOrder, rightInOrder);
        return node;
    }
};