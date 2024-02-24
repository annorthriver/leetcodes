#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "utils.h"
#include <unordered_map>
using namespace std;

// 枚举
vector<int> twoSum(vector<int>& nums, int target) {
  int len = nums.size();
  int i = 0, j = 0;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

// 哈希表 将遍历过的num到idx的map存入，然后使用target-x查询
vector<int> twoSum_(vector<int>& nums, int target) {
  std::unordered_map<int, int> num2idx;
  for (int i = 0; i < nums.size(); i++) {
    int subNum = target - nums[i];
    if (num2idx.count(subNum)) {
      return {num2idx[subNum], i};
    }
    num2idx[nums[i]] = i;
  }
  return {};
}

int main()
{
   vector<int> nums = {3, 2, 4};
   int target = 6;
   auto num = twoSum_(nums, target);
   print(num);
   return 0;
}