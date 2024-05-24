#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 回溯法，遍历所有可能性，会超时
    int dfs_0(int n) {
      if (n == 0) {
        return 0;
      }
      int count = INT_MAX;
      for (int i = 1; i * i <= n; i++) {
        count = min(count, dfs_0(n - i * i) + 1);
      }
      return count;
    }
    int numSquares_0(int n) {
      return dfs_0(n);
    }
    // 回溯法，记忆化搜索
    int dfs_1(int n, unordered_map<int, int> &map) {
      if (map.count(n)) {
        return n;
      }
      if (n == 0) {
        return 0;
      }
      int count = INT_MAX;
      for (int i = 1; i * i <= n; i++) {
        count = min(count, dfs_1(n - i * i, map) + 1);
      }
      map[n] = count;
      return count;
    }
    int numSquares_1(int n) {
      unordered_map<int, int> num2count;
      return dfs_1(n, num2count); 
    }
    // 动态规划 dp[i] = 1 + min(dp[i -j * j])(j:1~ sqrt(i))
    int numSquares(int n) {
      vector<int> dp(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        int count = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
          count = std::min(count, dp[i - j * j]);
        }
        dp[i] = count + 1;
      }
      return dp[n]; 
    }
    // 方法四：数学定理，四平方定理
};

int main () {
  Solution s;
  int n = 12;
  int res = s.numSquares(n);
  std::cout << "res: " << res << std::endl;
}