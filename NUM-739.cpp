#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 暴力法(超时)
    vector<int> dailyTemperatures_(vector<int>& temperatures) {
      int len = temperatures.size();
      vector<int> res;
      for (int i = 0; i < len; i++) {
        int t1 = temperatures[i];
        bool hasHigh = false;
        for (int j = i + 1; j < len; j++) {
          int t2 = temperatures[j];
          if (t1 < t2) {
            res.push_back(j - i);
            hasHigh = true;
            break;
          }
        }
        if (!hasHigh) {
          res.push_back(0);
        }
      }
      return res;
    }
    // 单调栈：用于求某个数左右两边大于或小于该数的最近的数
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int> s;
      int len = temperatures.size();
      vector<int> res(len, 0);
      for (int i = 0; i < len; i++) {
        // stack是递减栈（从栈底到栈顶）
        // 当前温度逐个与之前元素比较，如果比栈顶大，栈顶的元素找到最近的数，
        // 然后pop栈顶，再比较，直到为空或不满足比较条件，将当前元素index push到stack
        while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
          int prev = s.top();
          s.pop();
          res[prev] = i - prev;
        }
        s.push(i);
      }
      return res;
    }
};

int main () {
  Solution s;
  vector<int> vec{73,74,75,71,69,72,76,73};
  auto res = s.dailyTemperatures(vec);
  print(res);
}