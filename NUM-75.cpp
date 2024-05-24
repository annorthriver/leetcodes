#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 计数，扫描了两遍，不是最优解法
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (auto &num : nums) {
          count[num]++;
        }
        int idx = 0;
        for(int i = 0; i < 3; i++) {
          for (int j = 0; j < count[i]; j++) {
            nums[idx++] = i;
          }
        } 
    }
    // 双指针，扫描一次解法，先将0交换到头部，再将2交换到尾部, 2交换后不是1，需要回退i指针
    void sortColors(vector<int>& nums) {
      int size = nums.size();
      int p = 0, q = size - 1;
      for (int i = 0; i <= q; i++) {
        if (nums[i] == 0) {
          nums[i] = nums[p];
          nums[p] = 0;
          p++;
        }
        if (nums[i] == 2) {
          nums[i] = nums[q];
          nums[q] = 2;
          q--;
          if (nums[i] != 1) {
            i--;
          }
        }
      }
    }
    
};

int main () {
  Solution s;
  std::vector<int> nums{2,0,2,1,1,0};
  s.sortColors(nums);
  print(nums);
}