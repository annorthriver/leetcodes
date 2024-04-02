#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) return middle;
        if (nums[middle] >= nums[left]) {
            if (nums[middle] > target && nums[left] <= target) {
              right = middle - 1;
            } else {
              left = middle + 1;
            }
        } else {
          if (target <= nums[right] && target > nums[middle]) {
            left = middle + 1;
          } else {
            right = middle - 1;
          }
        }    
      }
      return -1;
    }
};

int main () {
  Solution s;
  vector<int> nums{4,5,6,7,0,1,2};
  int target = 0;
  auto res = s.search(nums, target);
  std::cout << "peak: " << res << std::endl;
}