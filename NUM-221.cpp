#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 方法一：暴力法，找到1的元素为左上角顶点，然后增加一行一列判断是否都为1，扩展边界
    // 方法二：动态规划法
    // dp[i][j]表示以i j为右下角点的正方形的最大边长
    // 如果matrix[i][j]= 1, dp[i][j]=min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> dp(m, vector<int>(n, 0));
      int maxLen = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
              if (i == 0 || j == 0) {
                dp[i][j] = 1;
              } else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
              }
              maxLen = max(maxLen, dp[i][j]);
            }
        }
      }
      return maxLen * maxLen;
    }
};

int main () {
  Solution s;
  vector<vector<char>> board{{'1','0','1','0','0'},{'1','0','1','1','1'},
  {'1','1','1','1','1'},{'1','0','0','1','0'}};
  auto res = s.maximalSquare(board);
  std::cout << "res: " << res << std::endl;
}