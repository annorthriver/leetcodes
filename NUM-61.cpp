#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include "utils.h"

// 使用栈
ListNode<int>* rotateRight(ListNode<int>* head, int k) {
  std::stack<ListNode<int>*> stack;
  auto *curNode = head;
  while(curNode) {
    stack.emplace(curNode);
    curNode = curNode->next;
  }
  curNode = head;
  k %= stack.size();
  if (k != 0) {
    stack.top()->next = head;
    for (int i = 0; i < k - 1; i++) {
      stack.pop();
    }
    curNode = stack.top();
    stack.pop();
    stack.top()->next = nullptr;
  }
  return curNode;
}

int main() {
  std::vector<int> nums1{1,2,3,4,5};
  // prepare list1
  ListCreater<int> list1(nums1);
  auto *l1 = list1.createList();
  list1.print();

  auto *res = rotateRight(l1, 2);
  printNonCycleList(res);
  return 0;
}

