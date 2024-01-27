#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int alternatingSubarray(vector<int>& nums) {
     int seqLen = -1;
     for (int i = 0; i < nums.size() - 1;) {
       int curNum = nums[i];
       if (curNum + 1 != nums[i+1]) {
         i++;
         continue;
       }
       int start = i;
       i+=2;
       while (i < nums.size() && nums[i] == nums[i-2]) {
         i++;
       }
       seqLen = std::max(seqLen, i - start);
       i--;
     }
     return seqLen;
}
int main()
{
   std::vector<int> nums{13,14,15,14};
   int maxNum = alternatingSubarray(nums);
   cout << "maximum num:" << maxNum;
   return 0;
}