#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp[i] = sum dp[i-cj]
    // 下面实现是排列数，不符合题目要求
    int change_error(int amount, vector<int>& coins) {
      if(coins.empty()) return 0;
      vector<int> dp(amount + 1, 0);
      dp[0] = 1;
      for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
          if (i-coins[j] >= 0) {
            dp[i] += dp[i-coins[j]];
          }
        }
      }
      return dp[amount];
    }
    // 求组合数，先遍历物品，再遍历背包
    int change(int amount, vector<int>& coins) {
      if(coins.empty()) return 0;
      vector<int> dp(amount + 1, 0);
      dp[0] = 1;
      for (int j = 0; j < coins.size(); j++) {
        for (int i = 1; i <= amount; i++) {
          if (i-coins[j] >= 0) {
            dp[i] += dp[i-coins[j]];
          }
        }
      }
      return dp[amount];
    }
};

int main () {
  Solution s;
  std::vector<int> coins{1,2,5};
  int amount = 5;
  auto res = s.change(amount, coins);
  std::cout << "nums: " << res << std::endl;
}