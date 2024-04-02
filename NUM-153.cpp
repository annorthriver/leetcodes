#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
      int left = 0, right = nums.size() - 2;
      while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[nums.size() - 1]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      return nums[left];
    }
};

int main () {
  Solution s;
  vector<int> nums{2,1};
  auto res = s.findMin(nums);
  std::cout << "min num: " << res << std::endl;
}