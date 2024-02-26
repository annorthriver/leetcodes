#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "utils.h"

ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
  auto *head = new ListNode<int>();
  auto *curNode = head;
  int div = 0, rem = 0;
  while (l1 || l2) {
    int num1 = 0, num2 = 0;
    if (l1) num1 = l1->val;
    if (l2) num2 = l2->val;
    int sum = num1 + num2 + div;
    div = sum / 10;
    rem = sum % 10;
    curNode->val = rem;        
    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;
    if (!l1 && !l2 && !div) {
      curNode->next = nullptr;
      return head;
    }
    curNode->next = new ListNode<int>();
    curNode = curNode->next;
  }
  if (div) {
    curNode->val = div;
    curNode->next = nullptr;
  }
  return head;
}

int main() {
  std::vector<int> nums1{9,9,9,9,9,9,9};
  std::vector<int> nums2{9,9,9,9};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();
  // prepare list2
  ListCreater<int> list2(nums2);
  auto *l2 = list2.createList();
  list2.print();
  auto *res = addTwoNumbers(l1, l2);
  printNonCycleList(res);
  return 0;
}

