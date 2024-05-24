#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 动态规划
    // 前位置的最优解未必是由前一个位置的最优解转移得到的。因为有负数的存在
    int maxProduct_(vector<int>& nums) {
      int len = nums.size();
      vector<int> dpMin(len), dpMax(len);
      dpMin[0] = nums[0];
      dpMax[0] = nums[0];
      int gMax = max(dpMax[0], INT_MIN);
      for (int i = 1; i < len; i++) {
        dpMax[i] = max(max(dpMin[i-1] * nums[i], dpMax[i-1] * nums[i]), nums[i]);
        dpMin[i] = min(min(dpMin[i-1] * nums[i], dpMax[i-1] * nums[i]), nums[i]);
        gMax = max(gMax, dpMax[i]);
      }
      return gMax;
    }
    // 方法二：正向遍历+反向遍历，因为负数奇数个需要正反两次遍历看哪个负数不被包含的结果更大
    // 如果有0出现的话，max从新开始计
    int maxProduct(vector<int>& nums) {
      int len = nums.size();
      int tmp = 1;
      int res = INT_MIN;
      for (int i = 0; i < len; i++) {
        tmp *= nums[i];
        res = max(res, tmp);
        if (tmp == 0) {
          tmp = 1;
        }
      }
      tmp = 1;
      for (int i = len - 1; i >= 0; i--) {
        tmp *= nums[i];
        res = max(res, tmp);
        if (tmp == 0) {
          tmp = 1;
        }
      }
      return res;
    }
};

int main () {
  Solution s;
  std::vector<int> nums{-2,3,-4};
  auto res = s.maxProduct(nums);
  std::cout << "len: " << res << std::endl;
}