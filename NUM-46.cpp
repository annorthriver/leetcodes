#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &res, int size, int depth, vector<int> &list) {
      if (depth == size) {
        res.emplace_back(list);
        return;  
      }
      for (int i = depth; i < size; i++) {
        swap(list[i], list[depth]);
        dfs(res, size, depth+1, list);
        swap(list[i], list[depth]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      dfs(res, nums.size(), 0, nums);
      return res;
    }
};

int main () {
  Solution s;
  vector<int> nums{1,2,3};
  auto res = s.permute(nums);
  print(res);
  return 0;
}