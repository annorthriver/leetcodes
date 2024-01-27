#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//双指针法：这里有个优化，只有right - left > 1才copy，防止原位操作
int removeDuplicates(vector<int>& nums) {
  int numSize = nums.size();
  if (numSize <= 1) {
    return 1;
  }
  int left = 0, right = 1;
  while(left < numSize && right < numSize) {
    if (nums[left] != nums[right]) {
      if (right - left > 1) {
        nums[left + 1] = nums[right];
      }
      left++;
    }
    right++;
  }
  return left + 1;
}
// 方法二：std 自带的unique方法和distance方法

int main()
{
   std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
   int len = removeDuplicates(nums);
   cout << "num:" << len;
   return 0;
}