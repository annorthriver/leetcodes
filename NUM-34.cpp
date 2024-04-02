#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 暴力搜索
    // 二分搜索，利用数组是有序的性质
    // 转换：
    // >= x,  >: >=x + 1 
    // 
    // 方式：闭区间，左闭右开，左开右开
    //  左闭右闭
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1; // [left, right]
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target) {
          // 此时不确定的区间是 M+1，R
          left = middle + 1; // [mid + 1, right]
        } else {
          // 此时不确定的区间是 L，Mid - 1
          right = middle - 1; // [left, mid - 1]
        }
      }
      return left;  // 或者返回right+1
    }
    //  左闭右开
    int search_1(vector<int>& nums, int target) {
      int left = 0, right = nums.size(); // [left, right）
      while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target) {
          left = middle + 1; // [mid + 1, right）
        } else {
          right = middle; // [left, mid）
        }
      }
      return left;  // 或者right
    }
    //  左开右开
    int search_2(vector<int>& nums, int target) {
      int left = -1, right = nums.size(); // （left, right）
      while (left + 1 < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target) {
          left = middle; // (mid, right）
        } else {
          right = middle; // (left, mid）
        }
      }
      return right;  // 或者left + 1
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      int start = search(nums, target);
      if (start == nums.size() || nums[start] != target) {
        return {-1, -1};
      }
      int end = search(nums, target + 1) - 1;
      return {start, end};
    }

};

int main () {
  Solution s;
  vector<int> nums{5,7,7,8,8,10};
  int target = 8;
  auto res = s.searchRange(nums, target);
  print(res);
}