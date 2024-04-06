#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // 优先队列，也就是堆排序实现，使用小根堆
      // 先初始化k个元素的小根堆，然后使用剩余的元素填堆
      // 如果比堆顶大，就替换，最后剩下k个最大，堆顶是第k大
      priority_queue<int, vector<int>, greater<int>> p;
      int size = nums.size();
      int i = 0;
      for (i = 0; i < k; i++) {
        p.push(nums[i]);
      }
      for (; i < size; i++) {
        if (nums[i] > p.top()) {
          p.pop();
          p.push(nums[i]);
        }
      }
      return p.top();
    }
};

int main()
{
   Solution s;
   std::vector<int> nums{3,2,1,5,6,4};
   int k = 2;
   int len = s.findKthLargest(nums, k);
   cout << "num:" << len;
   return 0;
}