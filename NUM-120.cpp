#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // original solution
    // dp[i,j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i,j]
    int minimumTotal_(vector<vector<int>>& triangle) {
      int m = triangle.size();
      int n = m;
      vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
      for (int i = 0; i < n; i++) {
        dp[m - 1][i] = triangle[m - 1][i];   
      }
      for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
          dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
      }
      return dp[0][0];
    }
    // optimize space
    int minimumTotal(vector<vector<int>>& triangle) {
      int m = triangle.size();
      vector<int> dp(triangle.back());
      for (int i = m - 2; i >= 0; i--) {
        int minSum = 0;
        for (int j = 0; j < i + 1; j++) {
          dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
      }
      return dp[0];
    }
};

int main () {
  Solution s;
  std::vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
  auto res = s.minimumTotal(triangle);
  std::cout << "min path: " << res << std::endl;
}