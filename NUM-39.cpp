#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &res, int idx, int sum, int &target, vector<int>& candidates, vector<int> &list) {
      if (sum == target) {
        res.push_back(list);
        return;
      }
      if (sum > target) {
        return;
      }
      int numSize = candidates.size();
      for (int i = idx; i < numSize; i++) {
        list.emplace_back(candidates[i]);
        int curSum = sum + candidates[i];
        dfs(res, i, curSum, target, candidates, list);
        list.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> list;
        dfs(res, 0, 0, target, candidates, list);
        return res;
    }
};

int main () {
  Solution s;
  vector<int> candidates{2,3,5};
  int target = 8;
  auto res = s.combinationSum(candidates, target);
  print(res);
  return 0;
}