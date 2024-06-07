#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 方法一：暴力法（超时）
    vector<int> maxSlidingWindow_(vector<int>& nums, int k) {
      vector<int> res;
      int len = nums.size();
      for (int i = k; i <= len; i++) {
       int begin = i - k;
       auto maxEle = max_element(nums.begin() + begin, nums.begin() + i);
       res.push_back(*maxEle);
      }
      return res;
    }
    // 方法二：优先队列
    // 方法三：双端单调递减队列，保证队首是最大值
    // 使用双端队列，新入的值要跟队尾的值比，替换比它小的值，保证单调性
    // 队首的值要在窗口滑动的时候判断是否还在窗口内
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res;
      int len = nums.size();
      std::deque<int> q;
      for (int i = 0; i < len; i++) {
        // 队尾入队比较保持队列单调递减
        while(!q.empty() && nums[q.back()] <= nums[i]) {
          q.pop_back();
        }
        // 新元素入队
        q.push_back(i);
        // 队头是否已经不在窗口里了
        if (q.front() <= i - k) {
          q.pop_front();
        }
        // 在完整的窗口形成后，将最大值放入
        if (i >= k - 1) {
          res.push_back(nums[q.front()]);
        }
      } 
      return res;
    }
};

int main () {
  Solution s;
  vector<int> nums{1,3,-1,-3,5,3,6,7};
  int k = 3;
  auto res = s.maxSlidingWindow(nums, k);
  print(res);
  return 0;
}