#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    void dfs(vector<string> &res, int l, int r, string str) {
      if (l == 0 && r == 0) {
        res.emplace_back(str);
        return;
      }
      if (l == r) {
        dfs(res, l - 1, r, str + "(");
      } else if (l < r) {
        if (l > 0) {
          dfs(res, l - 1, r, str + "(");
        }
        dfs(res, l, r-1, str + ")");
      }
    }
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      string str;
      dfs(res, n,  n, str);
      return res;
    }
};

int main () {
  Solution s;
  int n = 3, k = 2;
  auto res = s.generateParenthesis(n);
  print(res);
  return 0;
}