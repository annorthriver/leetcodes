#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

bool isValid(string s) {
  std::stack<char> strStack;
  strStack.push(s[0]);
  std::unordered_map<char, char> c2c = {{')', '('}, {'}', '{'}, {']', '['}};
  for (int i = 1; i < s.size(); i++) {
    if (c2c.count(s[i]) && !strStack.empty() &&strStack.top() == c2c[s[i]]) {
      strStack.pop();
      continue;
    }
    strStack.push(s[i]);
  }
  return strStack.empty();
}

int main()
{
   //std::string str("()[]{}");
   std::string str("(){}}{");
   bool res = isValid(str);
   cout << "res: " << res;
   return 0;
}