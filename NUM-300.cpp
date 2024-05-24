#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 转移方程：dp[i] = max(dp[j]) + 1 (j < i && nums[j] < nums[i])
    // res = max(dp[i]) 0 <= i < nums.size()
    int lengthOfLIS_(vector<int>& nums) {
      int len = nums.size();
      if (len == 1) return 1;
      vector<int> dp(len, 0);
      for (int i = 0; i < len; i++) {
        int maxNum = 0;
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j]) {
            maxNum = max(dp[j], maxNum);
          }
        }
        dp[i] = maxNum + 1;
      }
      return *max_element(dp.begin(), dp.end());
    }
    int lengthOfLIS(vector<int>& nums) {
      int len = nums.size();
      if (len == 1) return 1;
      vector<int> dp(len, 1);
      for (int i = 0; i < len; i++) {
        int maxNum = 0;
        bool needPlus = false;
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j]) {
            maxNum = max(dp[j], maxNum);
            needPlus = true;
          }
        }
        if (needPlus) {
          dp[i] = maxNum + 1;
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};

int main () {
  Solution s;
  std::vector<int> nums{10,9,2,5,3,7,101,18};
  auto res = s.lengthOfLIS(nums);
  std::cout << "len: " << res << std::endl;
}