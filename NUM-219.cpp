#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

// 哈希表
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  std::unordered_map<int, int> num2idx;
  for (int i = 0; i < nums.size(); i++) {
    if (num2idx.count(nums[i])) {
      if (i - num2idx[nums[i]] <= k) {
        return true;
      }
    }
    num2idx[nums[i]] = i;
  }
  return false;
}

// 方法二：使用滑动窗口 空间复杂度（O(k)）

int main()
{
   int k = 2;
   vector<int> nums{1,2,3,1,2,3};
   auto num = containsNearbyDuplicate(nums, k);
   std::cout << "ret: " << num << endl;
   return 0;
}