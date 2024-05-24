#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 哈希表，暴力法不符合题目要求
    // 方法一：二分查找，抽屉原理
    int findDuplicate(vector<int>& nums) {
      int len = nums.size();
      int left = 1, right = len - 1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int i = 0; i < len; i++) {
          if (nums[i] <= mid) {
            count++;
          }
        }
        if (count > mid) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }
    // 方法二：快慢指针法
    //int findDuplicate(vector<int>& nums) {

    //}
};

int main () {
  Solution s;
  std::vector<int> nums{1,3,4,2,2};
  int res = s.findDuplicate(nums);
  std::cout << "res: " << res << std::endl;
}