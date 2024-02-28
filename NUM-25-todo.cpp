#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

ListNode<int>* reverseKGroup(ListNode<int>* head, int k) {
  auto *dummy = new ListNode<int>();
  dummy->next = head;
  auto *pre = dummy;
  auto *next = dummy;
  while (next) {

    if (int i = 0; i < k; i++) {

    }

  }

  return nullptr;
}

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

