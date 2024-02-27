#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

ListNode<int>* mergeTwoLists(ListNode<int>* list1, ListNode<int>* list2) {
  ListNode<int> *head = nullptr, *tail = nullptr;
  while(list1 || list2) {
    int num = 0;
    if (list1 && list2) {
      if (list1->val >= list2->val) {
        num = list2->val;
        list2 = list2->next;
      } else {
        num = list1->val;
        list1 = list1->next;
      }
    } else if (list1) {
      num = list1->val;
      list1 = list1->next;
    } else {
      num = list2->val;
      list2 = list2->next;
    }
    if (!head) {
      head = tail = new ListNode<int>(num);
    } else {
      tail->next = new ListNode<int>(num);
      tail = tail->next;
    }
  }
  return head;
}

int main() {
  std::vector<int> nums1{1,2,4};
  std::vector<int> nums2{1,3,4};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();
  // prepare list2
  ListCreater<int> list2(nums2);
  auto *l2 = list2.createList();
  list2.print();
  auto *res = mergeTwoLists(l1, l2);
  printNonCycleList(res);
  return 0;
}

