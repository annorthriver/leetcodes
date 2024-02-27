#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// 随机链表的复制

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 方法一：递归+哈希表缓存
class Solution {
public:
    std::unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        if (!map.count(head)) {
            Node* newHead = new Node(head->val);
            map[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }
        return map[head];
    }
};

// 方法二：复制节点+分离链表
// 1. 根据遍历到的原节点创建对应的新节点，每个新创建的节点是在原节点后面
// 2. 原节点i的随机指针(如果有的话)，指向的是原节点j,那么新节点i的随机指针，指向的是原节点j的next
// 3. 将两个链表分离开


// 方法三：创建原节点->新节点的哈希map，然后建立根据原节点的关系创建新节点的关系