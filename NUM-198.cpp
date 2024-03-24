#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // dp[i] = max(dp[i-2]+nums[i], dp[i-1])
    int rob(std::vector<int>& nums) {
      if (nums.empty()) return 0;
      if (nums.size() == 1) {
        return nums[0];
      }
      std::vector<int> dp(nums.size(), 0);
      dp[0] = nums[0];
      dp[1] = std::max(nums[0], nums[1]);
      for (int i = 2; i < nums.size(); i++) {
        int cur = dp[i - 2] + nums[i];
        dp[i] = std::max(cur, dp[i-1]);
      }
      return dp.back();
    }
};

int main () {
  Solution s;
  std::vector<int> nums{1,2,3,1};
  auto res = s.rob(nums);
  std::cout << "coins: " << res << std::endl;
}