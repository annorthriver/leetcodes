#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 动态规划
    // dp[i] = dp[i-1] + nums[i], 如果 dp[i-1] > 0
    // dp[i] = nums[i]  dp[i-1] <= 0
    int maxSubArray_(vector<int>& nums) {
      int len = nums.size();
      vector<int> dp(len);
      dp[0] = nums[0];
      int max = dp[0];
      for (int i = 1; i < len; i++) {
        if (dp[i-1] <= 0) {
          dp[i] = nums[i];
        } else {
          dp[i] = dp[i - 1] + nums[i];
        }
        if (dp[i] > max) {
          max = dp[i];
        }
      }
      return max;
    }
    // 优化：直接在nums数组上做操作
    int maxSubArray(vector<int>& nums) {
      int res = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] > 0) {
          nums[i] = nums[i - 1] + nums[i];
        }
        if (nums[i] > res) {
            res = nums[i];
        }
      }
      return res;
    }
    // 方法三：线段树
};

int main()
{
   Solution s;
   std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
   int res = s.maxSubArray(nums);
   std::cout << "res: " << res << std::endl;
   return 0;
}