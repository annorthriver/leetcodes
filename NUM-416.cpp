#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 转化为0-1背包问题，将集合装满sum的一半
    bool canPartition(vector<int>& nums) {
      int len = nums.size();
      int sum = std::accumulate(nums.begin(), nums.end(), 0);
      // 如果nums的总和是奇数，一定不会分割成两个子集
      if (sum % 2 == 1) {
        return false;
      }
      int target = sum / 2;
      vector<int> dp(target + 1, 0);
      for (int i = 0; i < len; i++) {
        for (int j = target; j >= nums[i]; j--) {
          dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
      }
      if (dp[target] == target) {
        return true;
      }
      return false;
    }
};

int main () {
  Solution s;
  std::vector<int> nums{1,5,11,5};
  auto res = s.canPartition(nums);
  std::cout << "len: " << res << std::endl;
}