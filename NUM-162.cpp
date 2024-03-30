#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int left = 0;
      int right = nums.size() - 2;
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[middle + 1]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
      return left;
    }
};

int main () {
  Solution s;
  vector<int> nums{1,2,3,1};
  auto res = s.findPeakElement(nums);
  std::cout << "peak: " << res << std::endl;
}