#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 双指针法
int removeDuplicates(vector<int>& nums) {
  int numSize = nums.size();
  if (numSize <= 2) {
    return numSize;
  }
  int left = 2, right = 2;
  while(left < numSize && right < numSize) {
    if (nums[left-2] != nums[right]) {
      nums[left] = nums[right];
      left++;
    }
    right++;
  }
  return left;
}

int main()
{
   std::vector<int> nums{1};
   int len = removeDuplicates(nums);
   cout << "num:" << len;
   return 0;
}