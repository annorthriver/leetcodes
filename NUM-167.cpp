#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 双指针法
vector<int> twoSum(vector<int>& numbers, int target) {
  int left = 0, right = numbers.size() - 1;
  while (left < right) {
    auto sum = numbers[left] + numbers[right];
    if (sum == target) {
      break;
    }
    if (sum > target) {
      right--;
    }
    if (sum < target) {
      left++;
    }  
  }
  return {left + 1, right + 1};
}
// 二分查找

int main()
{
   std::vector<int> nums{2, 7, 11, 15};
   int target = 9;
   auto sub = twoSum(nums, target);
   print(sub);
   return 0;
}