#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "utils.h"

ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
  ListNode<int> * head = nullptr, *tail = nullptr;
  int carry = 0;
  while (l1 || l2) {
    int num1 = l1 ? l1->val : 0;
    int num2 = l2 ? l2->val : 0;
    int sum = num1 + num2 + carry;
    int carry = sum /10;
    int val = sum % 10;
    if (!head) {
      head = new ListNode<int>(val);
      tail = head;
    } else {
      tail->next = new ListNode<int>(val);
      tail = tail->next;
    }
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
  }
  if (carry) {
    tail->next = new ListNode<int>(carry);
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

