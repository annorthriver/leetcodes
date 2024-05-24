#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 双栈法
    // 1. num栈 + string 栈
    // 2. 遇到[，数字，字符，进栈
    // 3. 遇到]，弹出string栈拼接字符直到遇到[,然后重复这个str,放入string栈
    // 4. 继续遍历s
    string decodeString(string s) {
      stack<int> numStack;
      stack<string> strStack;
      for (int i = 0; i < s.size(); i++) {
        char curChar = s[i];
        if (std::isdigit(curChar)) {
          int digit = 0;
          while(std::isdigit(curChar)) {
            digit = digit * 10 + (curChar - '0');
            curChar = s[++i];
          }
          numStack.push(digit);
        }
        if (curChar == '[') {
          strStack.push("[");
        } else if (curChar == ']') {
          std::string str("");
          while(strStack.top() != "[") {
            str.insert(0, strStack.top());
            strStack.pop();
          }
          strStack.pop();
          std::string repStr("");
          for (int k = 0; k < numStack.top(); k++) {
            repStr+=str;
          }
          numStack.pop();
          strStack.push(repStr);
        } else {
          strStack.push(string(1, s[i]));
        }
      }
      std::string res("");
      while(!strStack.empty()) {
        res.insert(0, strStack.top());
        strStack.pop();
      }
      return res;
    }
};
int main () {
  Solution s;
  string str = "3[a20[c]]";
  auto res = s.decodeString(str);
  std::cout << "res: " << res << std::endl;
}