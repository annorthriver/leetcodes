#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "utils.h"

// 使用哈希表
bool hasCycle(ListNode<int> *head) {
  std::unordered_set<ListNode<int> *> set;
  auto *curNode = head;
  while (curNode) {
    if (set.count(curNode)) {
      return true;
    }
    set.emplace(curNode);
    curNode = curNode->next;
  }
  return false;
};

// 快慢指针法
bool hasCycle_(ListNode<int> *head) {
  if (!head) {
    return false;
  }
  auto *slowNode = head;
  auto *fastNode = head->next;
  while (slowNode && fastNode) {
    if (slowNode == fastNode) {
      return true;
    }
    slowNode = slowNode->next;
    fastNode = fastNode->next ? fastNode->next->next : nullptr;
  }
  return false;
};

int main() {
  std::vector<int> nums{3, 2, 0, -4};
  int pos = 1;
  ListCreater<int> list(nums);
  auto *head = list.createList();
  list.createCycle(pos);
  list.print();
  auto res = hasCycle_(head);
  std::cout << "res: " << res << std::endl;
  return 0;
}

