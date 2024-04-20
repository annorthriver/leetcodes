#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // Kadane算法
    // Kadane算法是一种用于解决最大子数组和问题的动态规划算法。这类问题的目标是在给定整数数组中找到一个连续的子数组，使其元素之和最大（数组含有负数）。算法的核心思想是通过迭代数组的每个元素，维护两个变量来跟踪局部最优解和全局最优解。Kadane算法的时间复杂度为O(n)，其中n是数组的长度，因此它是解决这个问题的高效方法
    int maxSubarraySumCircular(std::vector<int>& nums) {
      int len = nums.size();
      int preMax = nums[0], maxRes = nums[0];
      int preMin = nums[0], minRes = nums[0];
      int sum = nums[0];
      for (int i = 1; i < len; i++) {
        preMax = std::max(nums[i], preMax + nums[i]);
        maxRes = std::max(maxRes, preMax);
        
        preMin = std::min(nums[i], preMin + nums[i]);
        minRes = std::min(minRes, preMin);
        sum += nums[i];
      }
      return sum == minRes? maxRes : std::max(maxRes, sum-minRes);
    }
};

int main()
{
   Solution s;
   std::vector<int> nums{1,-2,3,-2};
   int res = s.maxSubarraySumCircular(nums);
   std::cout << "res: " << res << std::endl;
   return 0;
}