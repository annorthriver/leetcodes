#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> strs;
      int size = nums.size();
      if (size == 0) {
        return {};
      }
      int begin = nums[0];
      int pre = begin;
      for (int i = 1; i < size; ++i) {
        int tmp = nums[i];
        if (tmp == pre + 1) {
          pre = tmp;
          continue;
        } else {
          std::string str = std::to_string(begin);
          if (begin != pre) {
            str += "->" + std::to_string(pre);
          }
          strs.push_back(str);
          begin = tmp;
          pre = begin;
        }
      }
      std::string str = std::to_string(begin);
      if (begin != pre) {
            str += "->" + std::to_string(pre);
      }
      strs.push_back(str);
      return strs;
    }
};

int main () {
  Solution s;
  vector<int> nums{0,2,3,4,6,8,9};
  auto res = s.summaryRanges(nums);
  print(res);
}