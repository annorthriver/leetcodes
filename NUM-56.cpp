#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> res;
      vector<int> pre;
      if (intervals.size() == 0) {
        return {};
      }
      // 注意一定先排序，防止在将结果放到结果里后再出现区间重叠
      sort(intervals.begin(), intervals.end());
      int size = intervals.size();
      int begin, end;
      for (int i = 0; i < size; i++) {
        vector<int> cur = intervals[i];
        if (pre.empty()) {
          pre = cur;
          begin = pre[0];
          end = pre[1];
          continue;
        }
        if (end >= cur[0] && begin <= cur[1]) {
          begin = std::min(begin, cur[0]);
          end = std::max(end, cur[1]);
          continue;
        } else {
          res.push_back({begin, end});
          pre = cur;
          begin = cur[0];
          end = cur[1];
        }
      }
      res.push_back({begin, end});
      return res;
    }
};

int main () {
  Solution s;
  vector<vector<int>> interval{{1,4},{0,0}};
  //vector<vector<int>> interval{{1,3},{2,6},{8,10},{15,18}};
  auto res = s.merge(interval);
  print(res);
}