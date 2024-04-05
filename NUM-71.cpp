#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    // 消除"/"的影响，先将string分割
    // 使用stack保存
    // 然后拼接起来
    string simplifyPath(string path) {
      vector<string> strs;
      int pre = 0;
      auto pos = path.find('/');
      while (pos != string::npos) {
        if (pos > pre) {
          strs.push_back(path.substr(pre, pos - pre));
        }
        pre = pos + 1;
        pos = path.find('/', pre);
      }
      if (pre != path.size()) {
        strs.push_back(path.substr(pre));
      }
      stack<string> stack;
      for (auto &item : strs) {
       if (item == "." || item == "") {
         continue;
       }
       if (item == ".." && !stack.empty()) {
         stack.pop();
         continue;
       }
       if (item == "..") {
         continue;
       }
       stack.push(item);
      }
      string res;
      while (!stack.empty()) {
        auto &str = stack.top();
        res = "/" + str + res;
        stack.pop();
      }
      return res.empty() ? "/" : res;
    }
};

int main () {
  Solution s;
  string path = "/..";
  auto res = s.simplifyPath(path);
  std::cout << "res: " << res << std::endl;
}