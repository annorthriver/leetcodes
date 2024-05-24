#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> vec, int idx) {
      int len = nums.size();
      if (idx == len) {
        return;
      }
      vec.push_back(nums[idx]);
      res.push_back(vec);
      for (int i = 1; i < len - idx + 1; i++) {
        dfs(res, nums, vec, idx + i);
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      res.push_back({});
      for (int i = 0; i < nums.size(); i++) {
        dfs(res, nums, {}, i);
      }
      return res;
    }
};

int main () {
  Solution s;
  std::vector<int> nums{1,2,3,4};
  auto res = s.subsets(nums);
  print(res);
}