#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int num = points.size();
      int res = 1;
      for (int i = 0; i < num; i++) {
        auto x = points[i]; 
        for (int j = i + 1; j < num; j++) {
          auto y = points[j];
          int cnt = 2;
          for (int k = j + 1; k < num; k++) {
            auto p = points[k];
            int diff1 = (x[1] - y[1]) * (y[0] - p[0]);
            int diff2 = (y[1] - p[1]) * (x[0] - y[0]);
            if (diff1 == diff2) cnt++;
          }
          res = max(res, cnt);        
        }
      }
      return res;
    }
};

int main() {
  vector<vector<int>> points=
    {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
  Solution s;
  int max = s.maxPoints(points);
  std::cout << "max: " << max << std::endl;
}