#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//维护最远能到达的距离，如果最远能到达的距离大于等于数组最大index，那么就返回true
bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxLen = 0;
        for (int i = 0; i < size; i++) {
            if (i <= maxLen) {
                maxLen = std::max(maxLen, i + nums[i]);
                if (maxLen >= size - 1) {
                    return true;
                }
            }
        }
        return false;
}

int main()
{
   std::vector<int> nums{3,2,1,0,4};
   bool can = canJump(nums);
   cout << "num:" << can;
   return 0;
}