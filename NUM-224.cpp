#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    // 方法一：逆波兰表达式（Rverse Polish Notation,RPN）
    // 需要中缀表达式转后缀表达式
    // 方法二：双栈法
    int calculate(string s) {
      stack<int> nums;
      nums.push(0);
      // 去掉空格
      auto pos = s.find(" ");
      while (pos != string::npos) {
        s.replace(pos, 1, "");
        pos = s.find(" ");
      }
      stack<char> ops;
      int len = s.size();
      for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(') {
          ops.push(c);
        } else if (c == ')') {
          while (!ops.empty()) {
            char op = ops.top();
            if (op != '(') {
              calculate(nums, ops);
            } else {
              ops.pop();
              break;
            }
          }
        } else if (std::isdigit(c)) {
          int curNum = 0;
          int j = i;
          while (j < len && std::isdigit(s[j])) {
            curNum = curNum * 10 + (s[j++] - '0');
          }
          nums.push(curNum);
          i = j - 1;
        } else {
          if (i > 0 && (s[i - 1] == '(')) {
            nums.push(0);
          }
          while(!ops.empty() && ops.top() != '(')
              calculate(nums, ops);
          ops.push(c);
        }
      }
      while(!ops.empty())
          calculate(nums, ops);
      return nums.top();
    }
    void calculate(stack<int> &nums, stack<char> &ops) {
      if (nums.size() < 2 || ops.empty()) {
        return;
      }
      int rhs = nums.top();
      nums.pop();
      int lhs = nums.top();
      nums.pop();
      int op = ops.top();
      ops.pop();
      nums.push(op == '+' ? lhs + rhs : lhs - rhs);
    }
    // 方法三：编译原理中的词法分析

};

int main () {
  Solution sol;
  std::string s("(1+(4+5+2)-3)+(6+8)");
  auto res = sol.calculate(s);
  std::cout << "res: " << res << std::endl;
  return 0;
}