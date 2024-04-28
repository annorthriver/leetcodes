#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

ListNode<int>* reverseBetween_(ListNode<int>* head, int left, int right) {
  auto *curNode = head;
  int pos = 1;
  while(curNode) {
    if (left >= right) {
      break;
    }
    if (pos == left) {
      int rPos = pos + 1;
      auto *rNode = curNode->next;
      while (rNode) {
        if (rPos == right) {
          int tmp = rNode->val;
          rNode->val = curNode->val;
          curNode->val = tmp;
          break;
        }
        rPos++;
        rNode = rNode->next;
      }
      left++;
      right--;
    }
    pos++;
    curNode = curNode->next;
  }
  return head;
}

ListNode<int>* reverseBetween(ListNode<int>* head, int left, int right) {
  ListNode<int> dummy;
  dummy.next = head;
  auto *pre1 = &dummy;
  // 找到left的前一个节点
  for (int i = 0; i < left - 1; i++) {
    pre1 = pre1->next;
  }
  // 逐个反转left到right之间的节点
  ListNode<int> *pre2 = nullptr, *cur = pre1->next;
  for (int i = 0; i < right - left + 1; i++) {
    auto *tmp = cur->next;
    cur->next = pre2;
    pre2 = cur;
    cur = tmp;
  }
  // 此时，pre1的next仍然是未反转的起始node，需要把它接到cur
  pre1->next->next = cur;
  // 修改pre1的next为反转的起始位置pre2
  pre1->next = pre2;
  return dummy.next;
}

int main() {
  std::vector<int> nums{1,2,3,4,5};
  ListCreater<int> list(nums);
  auto *l = list.createList();
  list.print();
  auto *res = reverseBetween(l, 2, 4);
  printNonCycleList(res);
  return 0;
}

