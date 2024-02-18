#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：暴力双层循环
// 方法二：前缀和 + 二分查找，因为是n个正整数，所以前缀和一定是单调递增，保证了正确性

// 方法三：滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
  int length = nums.size();
  if (length == 0) {
    return 0;
  }
  int minSize = INT_MAX;
  int sum = 0, left = 0;
  for (int right = 0; right < length; right++) {
    sum += nums[right];
    while (sum >= target && left <= right) {
      // 保存最小索引差
      minSize = std::min(minSize, right - left + 1);
      // 将左侧的值从sum里减去，然后将左侧的指针右移
      sum-=nums[left];
      left++;
    }
  }
  return minSize == INT_MAX ? 0 : minSize;
}

int main()
{
   std::vector<int> nums{1, 4, 4};
   int target = 4;
   int len = minSubArrayLen(target, nums);
   cout << "num:" << len;
   return 0;
}