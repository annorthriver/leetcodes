#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 一共在第i天有五种状态
    // dp[i][0]: 不持有股票的现金
    // dp[i][1]: 第一次买入股票后的现金，dp[i][1] = max(dp[i-1][0]-price[i], dp[i-1][1]) 第i天第一次买入或者维持i-1天第一次买入的状态 
    // dp[i][2]: 第一次卖出股票后的现金, dp[i][2] = max(dp[i-1][1]+price[i], dp[i-1][2]) 第i天第一次卖出或者维持i-1天第一次卖出的状态
    // dp[i][3]: 第二次买入股票后的现金, dp[i][3] = max(dp[i-1][2]-price[i], dp[i-1][3]) 第i天第二次买入或者维持i-1天第二次买入的状态
    // dp[i][4]: 第二次卖出股票后的现金, dp[i][4] = max(dp[i-1][3]+price[i], dp[i-1][4]) 第i天第二次卖出或者维持i-1天第二次卖出的状态
    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      vector<vector<int>> dp(len, vector<int>(5, 0));
      dp[0][0] = 0;
      // 当天第一次买入后的现金
      dp[0][1] = -prices[0];
      // 当天第一次买入后又卖出的现金
      dp[0][2] = 0;
      // 当天第一次买入后又卖出第二次买入的现金
      dp[0][3] = -prices[0];
       // 当天第一次买入后又卖出第二次买入再卖出的现金
      dp[0][4] = 0;
      for (int i  = 1; i < len; i++) {
        dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
        dp[i][2] = max(dp[i-1][1]+prices[i], dp[i-1][2]);
        dp[i][3] = max(dp[i-1][2]-prices[i], dp[i-1][3]);
        dp[i][4] = max(dp[i-1][3]+prices[i], dp[i-1][4]);
      }
      // dp[len-1][4]包括了第一次买入卖出的情况，如果第一次卖出已经是最大值了，那么我们可以在当天立刻买入再立刻卖出。
      return dp[len-1][4];
    }
};

int main()
{
   Solution s;
   std::vector<int> nums{3,3,5,0,0,3,1,4};
   int res = s.maxProfit(nums);
   std::cout << "res: " << res << std::endl;
   return 0;
}