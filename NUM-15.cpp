#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 先从小到大排序
// 然后固定第一个数，双指针前后移动，因为是排序了，所以如果sum < 0,需要增大数，左指针右移，如果sum > 0, 需要减少数，右指针左移
vector<vector<int>> threeSum(vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  if (nums[0] > 0) {
    return {};
  }
  auto size = nums.size();
  std::vector<std::vector<int>> res;
  for (auto i = 0; i < size - 2; i++) {
    int j = i + 1, k = size - 1;
    if (i > 0 && nums[i - 1] == nums[i]) {
      continue;
    }
    while (j < k) {
      auto sum = nums[i] + nums[j] + nums[k];
      if (sum == 0) {
        res.push_back({nums[i], nums[j], nums[k]});
      }
      if (sum < 0) {
        do {
          j++;
        } while (j < k && nums[j] == nums[j - 1]);
        continue;
      }
      if (sum > 0) {
        do {
          k--;
        } while (j < k && nums[k] == nums[k + 1]);
        continue;
      }
      do {
        j++;
      } while (j < k && nums[j] == nums[j - 1]);
      do {
        k--;
      } while (j < k && nums[k] == nums[k + 1]);
    }
  }
  return res;
}

int main()
{
   std::vector<int> nums{-1,0,1,2,-1,-4};
   auto sums = threeSum(nums);
   print(sums);
   return 0;
}