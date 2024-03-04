
//构建完根节点后，一定要先构建右子树，再构建左子树，这样左子树的根节点才能被正确取到（即在右子树构建完成后）
class Solution {
    int endIdx;
    unordered_map<int, int> index;
public:
    TreeNode* buildMyTree(vector<int>& inorder, vector<int>& postorder,
                          int leftIdx, int rightIdx) {
        if (leftIdx > rightIdx) {
            return nullptr;
        }
        int rootVal = postorder[endIdx];
        auto* node = new TreeNode(rootVal);
        int pos = index[rootVal];
        endIdx--;
        node->right = buildMyTree(inorder, postorder, pos + 1, rightIdx);
        node->left = buildMyTree(inorder, postorder, leftIdx, pos - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        endIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildMyTree(inorder, postorder, 0, endIdx);
    }
};