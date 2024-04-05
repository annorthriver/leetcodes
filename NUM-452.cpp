#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    // 贪心，先排序，只要当前区间大于前一个的最小右边界，就需要一只箭
    int findMinArrowShots(vector<vector<int>>& points) {
      std::sort(points.begin(), points.end(), [](vector<int> &lhs, vector<int>&rhs){ return lhs[0] < rhs[0];});
      int count = 1;
      for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > points[i - 1][1]) {
          count++;
        } else {
          points[i][1] = min(points[i][1], points[i - 1][1]);
        }
      }
      return count;
   }
};

int main () {
  Solution s;
  vector<vector<int>> interval{{10,16},{2,8},{1,6},{7,12}};
  auto res = s.findMinArrowShots(interval);
  std::cout << "res: " << res << std::endl;
}