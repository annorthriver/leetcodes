#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// 左移到符号位，然后使用立即数判断符号位是否为1
int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
   int numSize = nums.size();

   int sum = 0;
   for (int i = 0; i < numSize; i++) {
     int curIdx = i;
     int setPos = 0;
     for (int j = 0; j < 32; j++) {
       if ((curIdx & 0x80000000) == 0x80000000) {
         setPos += 1;
       }
       curIdx <<= 1;
     }
     if (setPos == k) {
       sum += nums[i];
     }
   }
   return sum;
}

// 方法2：bit true的统计使用i % 2获取最低的二进制位，然后i / 2

// 方法3：使用分治思想解决，多个立即数

int main()
{
   std::vector<int> nums{4,3,2,1};
   int maxNum = sumIndicesWithKSetBits(nums,2);
   std::cout << "maximum num:" << maxNum;
   return 0;
}