#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    // 方法一：哈希表，空间复杂度不符合要求
    // 方法二：排序 + 二分查找
    // 方法三：将数组视为哈希表 要找的数一定在[1, N+1]的区间,因为如果按照1~N放入，则会是N+1，如果有其它数，那个被替代的整数索引位置就是缺失的正数
    //        将x映射到x-1的位置上
    int firstMissingPositive(vector<int>& nums) {
      int len = nums.size();
      // 遍历nums，nums[i] > 0，将nums[i]-1放到对应的位置上
      for (int i = 0; i < len; i++) {
        while(nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i]) {
          std::swap(nums[nums[i]-1], nums[i]);
        }
      }
      for (int i = 1; i <= len; i++) {
        if (nums[i-1] != i) {
          return i;
        }
      }
      return len + 1;
    }
};

int main () {
  Solution s;
  vector<int> nums{1,2,0};
  int target = 8;
  auto res = s.firstMissingPositive(nums);
  std::cout << "res: " << res << std::endl;
  return 0;
}