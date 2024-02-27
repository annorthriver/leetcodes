#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

ListNode<int>* reverseBetween(ListNode<int>* head, int left, int right) {
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

int main() {
  std::vector<int> nums{1,2,3,4,5};
  ListCreater<int> list(nums);
  auto *l = list.createList();
  list.print();
  auto *res = reverseBetween(l, 2, 4);
  printNonCycleList(res);
  return 0;
}

