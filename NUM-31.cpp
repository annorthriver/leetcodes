#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 1. 从尾部往前找到第一个升序对(i, j)
// 2. 从尾部开始第一个大于num[i]的数num[k]，交换i, k
// 3. 将j，end的数进行升序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int len = nums.size();
      int i = len - 2, j = len - 1, k = len - 1;
      // 找到从后往前第一个升序对
      while (i >= 0 && nums[i] >= nums[j]) {
        i--;
        j--;
      }
      // 
      if (i >= 0) {
        while (k >= 0 && nums[i] >= nums[k]) {
          k--;
        }
        std::swap(nums[i], nums[k]);
      }
      k = len - 1;
      while (j < k) {
        std::swap(nums[j], nums[k]);
        j++;
        k--;
      }
    }
};

int main () {
  Solution s;
  std::vector<int> nums{1,2,3,8,5,7,6,4};
  s.nextPermutation(nums);
  print(nums);
}