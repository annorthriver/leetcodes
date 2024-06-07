#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 前缀和 + 哈希表
    int subarraySum(vector<int>& nums, int k) {
      int len = nums.size();
      vector<int> prefixSum(len + 1, 0);
      for (int i = 0; i < len; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
      }
      unordered_map<int, int> prefix2count;
      int count = 0;
      for (auto &s : prefixSum) {
        if (prefix2count.count(s - k)) {
          count += prefix2count[s - k];
        }
        prefix2count[s]++;
      }
      return count;
    }
};

int main () {
  Solution s;
  vector<int> grid = {1,1,1};
  int k = 2;
  auto res = s.subarraySum(grid, k);
  std::cout << "res: " << res << std::endl;
  return 0;
}