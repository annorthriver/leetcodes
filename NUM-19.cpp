#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

// 维护两个指针，中间相差 n step, 然后同时移动指针，当右指针到end时，删除左指针
// 注意，左指针可以指向哑元节点，这样到终点时，左指针可以指向要删除的前一个节点
ListNode<int>* removeNthFromEnd(ListNode<int>* head, int n) {
  auto *left = new ListNode<int>();
  left->next = head;
  auto *right = head;
  for (int i = 0; i < n; i++) {
    right = right->next;
  }
  while (right) {
    right = right->next;
    left = left->next;
  }
  left->next = left->next->next;
  auto *res = left->next;
  return res;
}

// 方法二：计算链表长度，然后删除len-n+1位置的的node

// 方法三：入栈 +出栈n个元素

int main() {
  std::vector<int> nums1{1,2};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();
  auto *res = removeNthFromEnd(l1, 2);
  printNonCycleList(res);
  return 0;
}

