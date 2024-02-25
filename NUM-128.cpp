#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
using namespace std;

// 哈希表去重，然后维护最大长度，注意起始点跳过无效遍历，即curNum-1不在哈希表里
int longestConsecutive(vector<int>& nums) {
  std::unordered_set<int> numSet;
  for (const auto &num : nums) {
    numSet.emplace(num); 
  }
  int maxLen = 0;
  for (auto num : numSet) {
    if (!numSet.count(num - 1)) {
      int nextNum = num + 1;
      int len = 1;
      while (numSet.count(nextNum)) {
        len++;
        nextNum++;
      }
      maxLen = std::max(maxLen, len);
    }
  }
  return maxLen;
}

int main()
{
   //vector<int> nums{100,4,200,1,3,2};
   //vector<int> nums{0,3,7,2,5,8,4,6,0,1};
   vector<int> nums{};
   auto num = longestConsecutive(nums);
   std::cout << "ret: " << num << std::endl;
   return 0;
}