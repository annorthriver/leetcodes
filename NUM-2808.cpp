#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 扩散元素，环形数组(i, (i-1+n)%n, (i+1)%n)，使用哈希表
// x a b c d e x，两个x之间（假设下标为i j）的元素扩散为x，需要花费j - i - 1 + 1 // 2，所以是j - i // 2
// 各个相同元素最大间距之间的最小值

int minimumSeconds(vector<int>& nums) {
   int size = nums.size();
   std::unordered_map<int, std::vector<int>> posMap;
   for (int i = 0; i < size; i++) {
     posMap[nums[i]].push_back(i); 
   }
   int minSec = size;
   for (auto &ele : posMap) {
      auto pos = ele.second;
     // 初始值是最后一个位置和第一个位置之间的距离，因为是环形数组
     int distance = pos[0] + size - pos.back();
     for (int j = 1; j < pos.size(); j++) {
       distance = std::max(distance, pos[j] - pos[j-1]);
     }
     minSec = std::min(minSec, distance);
   }
   return minSec / 2;
}

int main()
{
   std::vector<int> nums{2,1,3,3,2};
   int len = minimumSeconds(nums);
   cout << "num:" << len;
   return 0;
}