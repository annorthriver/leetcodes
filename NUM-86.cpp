#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

// 维护两个指针，small和large，然后把small和large拼到一起 
ListNode<int>* partition(ListNode<int>* head, int x) {
  auto *small = new ListNode<int>();
  auto *large = new ListNode<int>();
  auto *smallHead = small;
  auto *largeHead = large;
  while (head) {
    if (head->val < x) {
      small->next = head;
      small = small->next;
    } else {
      large->next = head;
      large = large->next;
    }
    head = head->next;
  }
  large->next = nullptr;
  small->next = largeHead->next;
  return smallHead->next;
}

int main() {
  std::vector<int> nums1{1,4,3,2,5,2};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();

  auto *res = partition(l1, 3);
  printNonCycleList(res);
  return 0;
}

