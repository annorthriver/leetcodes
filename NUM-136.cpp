#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

// 异或的性质
// 1. a 与 0 异或是 a
// 2. a 与 a 异或是 0
// 3. 结合律和交换律

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int res = 0;
      for (auto &num : nums) {
        res ^= num;
      }
      return res;
    }
};

int main () {
  Solution s;
  vector<int> nums{2, 2, 1};
  auto res = s.singleNumber(nums);
  std::cout << "res: " << res << std::endl;
}