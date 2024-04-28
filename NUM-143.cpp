#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 方法一：vector+首尾替换
    void reorderList_(ListNode* head) {
      if (!head) {
        return;
      }
      std::vector<ListNode *> nodes;
      auto *temp = head;
      while (temp) {
        nodes.push_back(temp);
        temp = temp->next;
      }
      int i = 0, j = nodes.size() - 1;
      while (i < j) {
        nodes[i++]->next = nodes[j];
        if (i == j) {
          break;
        }
        nodes[j--]->next = nodes[i];
      }
      nodes[i]->next = nullptr;
      return;
    }
    // 方法二：寻找链表中点 + 链表逆序 + 合并链表
    void reorderList(ListNode* head) {
      if (!head) {
        return;
      }
      ListNode *mid = middleNode(head);
      ListNode *l1 = head;
      ListNode *l2 = mid->next;
      mid->next = nullptr;
      l2 = reverseNode(l2);
      connetNode(l1, l2);
    }
    ListNode *middleNode(ListNode *head) {
      ListNode *slow = head;
      ListNode *fast = head;
      while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
    ListNode *reverseNode(ListNode *head) {
      ListNode *prev = nullptr;
      ListNode *cur = head;
      while (cur) {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
      }
      return prev;
    }
    void connetNode(ListNode *l1, ListNode* l2) {
      ListNode *temp1;
      ListNode *temp2;
      while (l1 && l2) {
        temp1 = l1->next;
        temp2 = l2->next;
        l1->next = l2;
        l1 = temp1;
        l2->next = temp1;
        l2 = temp2;
      }
    }
};

ListNode *constructList(std::vector<int> &nums) {
  ListNode dummy;
  dummy.next = new ListNode(nums[0]);
  ListNode *head = dummy.next;
  for (int i = 1; i < nums.size(); i++) {
    head->next = new ListNode(nums[i]);
    head = head->next;
  }
  return dummy.next;
}

int main() {
  Solution s;
  std::vector<int> nums{1,2,3,4,5};
  auto list = constructList(nums);
  s.reorderList(list);
  while (list) {
    std::cout << list->val << std::endl;
    list = list->next;
  }
  return 0;
}