#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      unordered_set<ListNode *> nodes;
      while (headA) {
        nodes.insert(headA);
        headA = headA->next;
      }
      while (headB) {
        if (nodes.count(headB)) {
          return headB;
        }
        headB = headB->next;
      }
      return nullptr;
    }
    // 方法二：同时遍历，a遍历到结束后遍历b, b遍历结束后遍历a
    // 如果相交，则长度会相同
};