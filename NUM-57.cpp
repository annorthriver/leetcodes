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
      for (auto &interval : intervals) {
        
      }


    }
};

int main () {
  Solution s;
  vector<vector<int>> interval{{1,3},{6,9}};
  vector<int> newInterval{2,5};
  //vector<vector<int>> interval{{1,3},{2,6},{8,10},{15,18}};
  auto res = s.insert(interval, newInterval);
  print(res);
}