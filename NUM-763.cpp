#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 思路：遍历一遍string，记录每个char的pos
    // 然后维护begin，end，end随pos更新，如果当前已遍历的char到达maxEnd，切割，更新start
    vector<int> partitionLabels(string s) {
      vector<int> pos(26, -1);
      //遍历一遍string，记录每个char的pos
      for (int i = 0; i < s.size(); i++) {
        pos[s[i] - 'a'] = i;
      }
      vector<int> res;
      int start = 0, end = 0;
      //然后维护begin，end，end随pos更新，如果当前已遍历的char到达maxEnd，切割，更新start
      for (int i = 0; i < s.size(); i++) {
        end = std::max(end, pos[s[i] - 'a']);
        if (i == end) {
          res.push_back(i - start + 1);
          start = end + 1;
        }
      }
      return res;
    }
};

int main () {
  Solution s;
  string str = "ababcbacadefegdehijhklij";
  auto res = s.partitionLabels(str);
  print(res);
}