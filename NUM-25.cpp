#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "utils.h"
std::pair<ListNode<int>*, ListNode<int>*> reverse(ListNode<int>* head, ListNode<int>* tail) {
    ListNode<int>* prev = tail->next;
    ListNode<int>* p = head;
    while (prev != tail) {
        ListNode<int>* next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    return {tail, head};
}
// 方法一：循环k个一组的链表，然后将每个k子链表反转
ListNode<int>* reverseKGroup(ListNode<int>* head, int k) {
        ListNode<int>* hair = new ListNode(0);
        hair->next = head;
        ListNode<int>* pre = hair;
        while (head) {
            ListNode<int>* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode<int>* next = tail->next;
            std::tie(head, tail) = reverse(head, tail);
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
}
// 方法二：递归反转链表


int main() {
  std::vector<int> nums1{1,2,3,4,5};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();
  auto *res = reverseKGroup(l1, 2);
  printNonCycleList(res);
  return 0;
}

