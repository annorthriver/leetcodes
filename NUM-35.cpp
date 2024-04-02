#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int size = nums.size();
      int left = 0, right = size - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      return left;
    }
};

int main () {
  Solution s;
  int target = 5;
  vector<int> nums{1, 3, 5, 6};
  auto res = s.searchInsert(nums, target);
  std::cout << "pos: " << res << std::endl;
}