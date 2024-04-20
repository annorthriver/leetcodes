#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "utils.h"

using namespace std;

class Solution {
public:
    // 使用小根堆，取k次小根顶部元素，并且每取一次将下一个索引对放进去
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int len1 = nums1.size();
      int len2 = nums2.size();
      vector<vector<int>> ans;
      auto cmp = [&](auto &a, auto &b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
      };
      priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);

      // 先将(i, 0)的索引对放入，然后在小根堆的更新中更新二索引,防止重复元素对放入
      for (int i = 0; i < std::min(k, len1); i++) {
        q.emplace(i, 0);
      }
      while (k--> 0 && !q.empty()) {
        auto [x, y] = q.top();
        q.pop();
        // 当前最小的元素对放入
        ans.push_back({nums1[x], nums2[y]});
        // 将下个元素对放入
        if (y + 1 < len2) {
          q.emplace(x, y + 1);
        }
      }
      return ans;
    }
};

int main()
{
   Solution s;
   std::vector<int> nums1{1, 7, 11};
   std::vector<int> nums2{2, 4, 6};
   int k = 3;
   auto res = s.kSmallestPairs(nums1, nums2, k);
   print(res);
   return 0;
}