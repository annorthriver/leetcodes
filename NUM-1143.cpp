#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 方法一：回溯+记忆化搜索
    // 方法二：动态规划
    int longestCommonSubsequence(string text1, string text2) {
      int m = text1.size(), n = text2.size();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (text1[i-1] == text2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
          } else {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
      return dp[m][n];
    }
};

int main () {
  Solution s;
  string text1 = "abc", text2 = "def";
  int res = s.longestCommonSubsequence(text1, text2);
  std::cout << "res: " << res << std::endl;
}