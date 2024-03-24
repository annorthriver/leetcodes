#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 动态转移方程：f(i) = min f(i - cj) + 1
    int coinChange(vector<int>& coins, int amount) {
      if (amount < 1) {
        return 0;
      }
      vector<int> dp(amount + 1, INT_MAX);
      dp[0] = 0;
      for (int i = 1; i <= amount; i++) {
        int minStep = INT_MAX / 2;
        for (int j = 0; j < coins.size(); j++) {
          if (i - coins[j] >= 0) {
            minStep = min(dp[i-coins[j]], minStep);
          }
        }
        dp[i] = minStep + 1;
      }
      int res = dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
      return res;
    }
};

int main () {
  Solution s;
  std::vector<int> coins{1,2,5};
  int amount = 11;
  auto res = s.coinChange(coins, amount);
  std::cout << "coins: " << res << std::endl;
}