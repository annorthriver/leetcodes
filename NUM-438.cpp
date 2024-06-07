#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 滑动窗口法
    bool identity(unordered_map<int, int> &sMap, unordered_map<int,int> &pMap) {
      if (pMap.size() != sMap.size()) {
        return false;
      }
      for (auto &[key, value]: pMap) {
        if (sMap[key] != value) {
          return false;
        }
      }
      return true;
    }
    vector<int> findAnagrams(string s, string p) {
      unordered_map<int, int> pMap;
      unordered_map<int, int> sMap;
      for (auto c : p) {
        pMap[c]++;
      }
      vector<int> res;
      int left = 0;
      for (int right = 0; right < s.size(); right++) {
        sMap[s[right]]++;
        if (right < p.size() - 1) {
          continue;
        }
        if (identity(sMap, pMap)) {
          res.push_back(left);
        }
        sMap[s[left]]--;
        if (sMap[s[left]] == 0) {
          sMap.erase(s[left]);
        }
        left++;
      }
      return res;
    }
};

int main () {
  Solution s;
  string str = "cbaebabacd";
  string ptr = "abc";
  auto res = s.findAnagrams(str, ptr);
  print(res);
  return 0;
}