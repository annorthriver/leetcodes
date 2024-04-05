#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string str) {
      return !(str == "+" || str == "-" || str == "*" || str == "/");
    }
    int evalRPN(vector<string>& tokens) {
      stack<int> intStack;
      for (auto &token : tokens) {
        if (isNumber(token)) {
          intStack.push(atoi(token.c_str()));
        } else {
          int num0 = intStack.top();
          intStack.pop();
          int num1 = intStack.top();
          intStack.pop();
          if (token == "+") {
            num1 += num0;
          } else if (token == "-") {
            num1 -= num0;
          } else if (token == "*") {
            num1 *= num0;
          } else {
            num1 /= num0;
          }
          intStack.push(num1);
        }
      }
      return intStack.top();
    }
};

int main () {
  Solution s;
  vector<string> tokens{"2","1","+","3","*"};
  auto res = s.evalRPN(tokens);
  std::cout << "res: " << res << std::endl;
}