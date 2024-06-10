#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 排序+ n/2选数
int majorityElement_(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() / 2];
}
//方法2：哈希表 使用unordered_map

//方法3：随机化

//方法4：分治

//方法5：Boyer-Moore 投票算法
int majorityElement(vector<int>& nums) {
  int x = 0, votes = 0;
  for (auto &num : nums) {
    // 每次投票抵消为0后，以当前num重新为起点
    // 最后一轮剩下的即为多数元素
    if (votes == 0) {
      x = num;
    }
    votes += ((num == x) ? 1 : -1);
  }
  return x;
}

int main()
{
   std::vector<int> nums{2,2,1,1,1,2,2};
   int len = majorityElement(nums);
   cout << "num:" << len;
   return 0;
}