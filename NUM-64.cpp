#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp[i][j] = min{dp[i-1][j], dp[i][j-1]} + grid[i][j]
    // 注意在第一行和第一列的dp中，不和0行0列比较min
    int minPathSum_(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          int minSum = std::min(dp[i-1][j], dp[i][j-1]);
          if (i - 1 == 0) {
            minSum = dp[i][j-1];
          } else if (j - 1 == 0) {
            minSum = dp[i-1][j];
          }
          dp[i][j] = minSum + grid[i-1][j-1];
        }
      }
      return dp[m][n];
    }
    // 优化空间，复用原矩阵空间
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          //跳过左上角点
          if (i == 0 && j == 0) continue;
          if (i == 0) {
            grid[i][j] += grid[i][j - 1];
          } else if (j == 0) {
            grid[i][j] += grid[i - 1][j];
          } else {
            grid[i][j] += std::min(grid[i][j - 1], grid[i - 1][j]);
          }
        }
      }
      return grid[m-1][n-1];
    }
};

int main () {
  Solution s;
  std::vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
  auto res = s.minPathSum(grid);
  std::cout << "nums: " << res << std::endl;
}