#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

// 三指针法：
ListNode<int>* deleteDuplicates(ListNode<int>* head) {
  auto *dummy = new ListNode<int>();
  dummy->next = head;
  auto *pre = dummy;
  auto *start = head;
  auto *end = head->next;
  while (end) {
    if (end->val == start->val) {
      while (end->next) {
        if (end->next->val != start->val) {
          break;
        }
        end->next = end->next->next;
      }
      // 只改pre->next，不改pre
      pre->next = end->next;
      start = end->next;
      end = end->next ? end->next->next : nullptr;
      continue;
    }
    end = end->next;
    start = start->next;
    pre = pre->next;
  }
  auto *res = dummy->next;
  delete dummy;
  return res;
}

// 简化代码： cur cur->next cur->next->next

int main() {
  std::vector<int> nums1{1,2,3,3,4,4,5};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();
  auto *res = deleteDuplicates(l1);
  printNonCycleList(res);
  return 0;
}

