#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 排序+ n/2选数
int majorityElement(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() / 2];
}
//方法2：哈希表 使用unordered_map

//方法3：随机化

//方法4：分治

//方法5：Boyer-Moore 投票算法

int main()
{
   std::vector<int> nums{2,2,1,1,1,2,2};
   int len = majorityElement(nums);
   cout << "num:" << len;
   return 0;
}