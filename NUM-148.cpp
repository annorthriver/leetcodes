/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *sortList(ListNode* head, ListNode* tail) {
      // 链表为空
      if (head == nullptr) {
        return head;
      }
      // 只包含一个节点(左闭右开区间)
      if (head->next == tail) {
        head->next = nullptr;
        return head;
      }
      // 快慢指针找中点
      ListNode* slow = head, *fast = head;
      while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
          fast = fast->next;
        }
      }
      ListNode* mid = slow;
      return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode *merge(ListNode *head1, ListNode *head2) {
      ListNode *dummyHead = new ListNode(0);
      ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
      while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->val <= temp2->val) {
          temp->next = temp1;
          temp1 = temp1->next;
        } else {
          temp->next = temp2;
          temp2 = temp2->next;
        }
        temp = temp->next;
      }
      if (temp1 != nullptr) {
        temp->next = temp1;
      } else if (temp2 != nullptr) {
        temp->next = temp2;
      }
      return dummyHead->next;
    }
    ListNode* sortList(ListNode* head) {
      return sortList(head, nullptr);
    }
};