#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 使用栈，每匹配一个(，索引入栈，每匹配一个 ( 维护一个maxLen
    // ()(()))
    int longestValidParentheses(string s) {
      int len = s.size();
      int maxLen = 0;
      stack<int> parenStack;
      parenStack.push(-1);
      for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
          parenStack.push(i);
        } else {
          parenStack.pop();
          if (!parenStack.empty()) {
            int curLen = i - parenStack.top();
            maxLen = std::max(curLen, maxLen);
          } else {
            parenStack.push(i);
          }
        }
      }
      return maxLen;
    }
    // 动态规划
};

int main () {
  Solution s;
  string str = "(()";
  int res = s.longestValidParentheses(str);
  std::cout << "res: " << res << std::endl;
}