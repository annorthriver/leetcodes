/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
          return nullptr;
        }
        std::queue<Node *> nodes;
        
        nodes.push(root);
        while (!nodes.empty()) {
          // 这里的要点是使用一个变量记录当前层级的数量，然后根据变量遍历这一层级
          int n = nodes.size();
          Node *lastNode = nullptr;
          for (int i = 0; i < n; i++) {
            auto *curNode = nodes.front();
            nodes.pop();
            if (curNode->left) {
              nodes.push(curNode->left);
            }
            if (curNode->right) {
              nodes.push(curNode->right);
            }
            if (i != 0) {
              lastNode->next = curNode;
            }
            lastNode = curNode;
          }
        }
        return root;
    }
};