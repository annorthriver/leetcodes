#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

bool hasCycle(ListNode<int> *head) {
  return false;
};

int main() {
  std::vector<int> nums{3, 2, 0, -4};
  int pos = 1;
  ListCreater<int> list(nums);
  auto *head = list.createList();
  auto res = hasCycle(head);
  std::cout << "res: " << res << std::endl;
  return 0;
}

