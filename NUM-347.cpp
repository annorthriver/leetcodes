#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // 通过map记录num的频次
      unordered_map<int,int> count;
      for (auto &num : nums) {
        count[num]++;
      }
      auto cmp = [&](int &a, int &b) {
        return count[a] > count[b];
      };
      // 建立小根堆
      priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
      // 遍历map，放入小根堆
      for (const auto &[key, value] : count) {
        if (q.size() < k) {
          q.push(key);
        } else if (value > count[q.top()]) {
          q.pop();
          q.push(key);
        }
      }
      // 清空queue，建立返回值。
      vector<int> res;
      while(!q.empty()) {
        res.push_back(q.top());
        q.pop();
      }
      return res;
    }
};

int main () {
  Solution s;
  vector<int> nums{1,1,1,2,2,3};
  int k = 2;
  auto res = s.topKFrequent(nums, k);
  print(res);
}