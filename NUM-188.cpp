#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      int len = prices.size();
      vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
      dp[0][0] = 0;
      for (int i = 1; i < 2 * k; i+=2) {
        dp[0][i] = -prices[0];
      }
      for (int i = 1; i < len; i++) {
        for (int j = 0; j < 2 * k - 1; j+=2) {
          dp[i][j + 1] = max(dp[i][j] - prices[i], dp[i - 1][j + 1]);
          dp[i][j + 2] = max(dp[i][j + 1] + prices[i], dp[i - 1][j + 2]); 
        }
      }
      return dp[len - 1][2 * k];
    }
};

int main()
{
   Solution s;
   std::vector<int> nums{3,2,6,5,0,3};
   int k = 2;
   int res = s.maxProfit(k, nums);
   std::cout << "res: " << res << std::endl;
   return 0;
}