#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这里使用了偷懒的erase方法，实际需要实现erase的过程
int removeElement(vector<int>& nums, int val) {
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    if (nums[i] == val) {
      nums.erase(nums.begin() + i);
      i--;
      size--;
    }
  }
  return size;
}

// 方法二：使用双指针实现元素移动

int main()
{
   std::vector<int> nums{0,1,2,2,3,0,4,2};
   int len = removeElement(nums, 2);
   cout << "maximum num:" << len;
   return 0;
}