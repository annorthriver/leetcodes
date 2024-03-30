#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp[i][j] 表示word1的第i-1个字符和word2的第i-1个字符相等需要的最小编辑距离
    // 
    int minDistance(string word1, string word2) {
      int len1 = word1.size();
      int len2 = word2.size();
      vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
      //初始化边界值
      for (int i = 0; i < len1; i++) {
        dp[i][0] = i;
      }
      for (int j = 0; j < len2; j++) {
        dp[0][j] = j;
      }
      for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
          if (word1[i-1] == word2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
          } else {
            dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
          }
        }
      }
      return dp[len1][len2];
    }
};

int main () {
  Solution s;
  std::string word1{"horse"},word2{"ros"};
  auto res = s.minDistance(word1, word2);
  std::cout << "min dis: " << res << std::endl;
}