#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 不需要遍历最后一个index，因为一定会到达
int jump(vector<int>& nums) {
  int size = nums.size();
  int maxLen = 0;
  int count = 0;
  int rightEnd = 0;
  for (int i = 0; i < size - 1; ++i) {
    maxLen = std::max(maxLen, i+nums[i]);
    if (i == rightEnd) {
      rightEnd = maxLen;
      count++;
    }
  }
  return count;
}

int main()
{
   std::vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
   int num = jump(nums);
   cout << "num:" << num;
   return 0;
}