#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res;
      int newL = newInterval[0], newR = newInterval[1];
      if (intervals.empty()) {
        res.push_back(newInterval);
      }
      for (auto &interval : intervals) {
        int L = interval[0], R = interval[1];
        if (!res.empty()) {
          auto &backInterval = res.back();
          // 完全包含
          if (backInterval[1] >= R) {
            continue;
          }
          // 右边部分包含，更新右端区间
          if (backInterval[1] >= L) {
            backInterval[1] = R;
            continue;
          }
          // 中间部分完全不相交
          if (backInterval[1] < newL && newR < L) {
            res.push_back(newInterval);
          }
        }
        // 处理不相交区间
        // 左边的,或者右边的
        if (newL > R || newR < L) {
          res.push_back(interval);
          continue;
        }
        // 新区间
        L = std::min(L, newL);
        R = std::max(R, newR);
        res.push_back({L, R});
      }
      // 处理完全不相交，在intervals前
      if (res.front()[0] > newR) {
        res.insert(res.begin(), newInterval);
      }
      // 处理完全不相交，在intervals后
      if (res.back()[1] < newL) {
        res.push_back(newInterval);
      }
      return res;
    }
};

int main () {
  Solution s;
  //vector<vector<int>> interval{{1,3},{6,9}};
  //vector<int> newInterval{2,5};
  vector<vector<int>> interval{{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> newInterval{4,8};
  //vector<vector<int>> interval{{1,5}};
  //vector<int> newInterval{0,0};
  //vector<vector<int>> interval{{3,5},{12,15}};
  //vector<int> newInterval{6,6};
  auto res = s.insert(interval, newInterval);
  print(res);
}